#include "expensiveclass.h"

ExpensiveClass::ExpensiveClass(QString *ref_to_lock_value, QThread *owner_thread)
{
    _to_be_locked=ref_to_lock_value;

    connect (owner_thread,SIGNAL(started()),this, SLOT(slotThreadStart()) );
    connect (owner_thread,SIGNAL(finished()),this, SLOT(slotThreadFinished()) );
}

void ExpensiveClass::slotThreadStart()
{
    this->_useLockToChange();

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

bool ExpensiveClass::_useLockToChange()
{
    QWriteLocker locker(&lock);
    *_to_be_locked="Value changed from another thread via locking.";
    return true;
}

