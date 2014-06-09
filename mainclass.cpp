#include "mainclass.h"

MainClass::MainClass(QObject *parent) :
    QObject(parent)
{
    thread=new QThread();
    worker=new ExpensiveClass(thread);
    worker->moveToThread(thread);
}

MainClass::~MainClass()
{
    thread->exit();
    thread->wait();
}

bool MainClass::runJob()
{
    string user_input;
    bool running=true;
    cout<<"Enter 1 to start, or 0 to stop.";

    while(running){
        cin>>user_input;

        if(user_input=="1"){
            cout<<"starting..."<<endl;
            thread->start();
        }
        else if (user_input=="0"){
            cout<<"stopping..."<<endl;
            thread->exit();
            running=false;
        }
        else{
            cout<<"invalid input."<<endl;
        }
    }

    cout<<"Done."<<endl;
    return true;
}
