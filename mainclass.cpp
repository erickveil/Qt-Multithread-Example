#include "mainclass.h"

MainClass::MainClass(QObject *parent) :
    QObject(parent)
{
    value_for_lock="Initial value before locking variable.";
    _value_for_signal="Initial vlaue before signal variable change.";

    thread=new QThread();
    worker=new ExpensiveClass(&value_for_lock, thread);
    worker->moveToThread(thread);

    cout<<value_for_lock.toStdString()<<endl;
    cout<<_value_for_signal.toStdString()<<endl;
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

    cout<<value_for_lock.toStdString()<<endl;
    cout<<_value_for_signal.toStdString()<<endl;
    cout<<"Done."<<endl;
    return true;
}

void MainClass::slotCrossThread(QString data)
{
    this->_value_for_signal=data;
}

