#include <QCoreApplication>
#include "mainclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainClass *run_target=new MainClass();
    run_target->runJob();

    return a.exec();
}
