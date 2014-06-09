#include "expensiveclass.h"

ExpensiveClass::ExpensiveClass(QThread *owner_thread)
{
    connect (owner_thread,SIGNAL(started()),this, SLOT(slotThreadStart()) );
    connect (owner_thread,SIGNAL(finished()),this, SLOT(slotThreadFinished()) );
}

void ExpensiveClass::slotThreadStart()
{
    QTimer *repeater = new QTimer(this);
    connect (repeater, SIGNAL(timeout()),this,SLOT(doProcess()) );
    repeater->start(2000);
}

void ExpensiveClass::slotThreadFinished()
{
    cout<<"end thread."<<endl;
}

void ExpensiveClass::doProcess()
{
    cout<<"Running..."<<endl;
}
