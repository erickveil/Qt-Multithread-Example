#ifndef EXPENSIVECLASS_H
#define EXPENSIVECLASS_H

#include <QObject>
#include <QTimer>
#include <iostream>
#include <QThread>
#include <QWriteLocker>

using namespace std;

class ExpensiveClass : public QObject
{
    Q_OBJECT
public:
    explicit ExpensiveClass(QString *ref_to_lock_value, QThread *owner_thread);

signals:
    void signalCrossThread(QString data);

public slots:
    void slotThreadStart();
    void slotThreadFinished();
    void doProcess();

private:
    QReadWriteLock lock;
    QString *_to_be_locked;
    bool _useLockToChange();

};

#endif // EXPENSIVECLASS_H
