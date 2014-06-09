#ifndef EXPENSIVECLASS_H
#define EXPENSIVECLASS_H

#include <QObject>
#include <QTimer>
#include <iostream>
#include <QThread>

using namespace std;

class ExpensiveClass : public QObject
{
    Q_OBJECT
public:
    explicit ExpensiveClass(QThread *owner_thread);

signals:

public slots:
    void slotThreadStart();
    void slotThreadFinished();
    void doProcess();

};

#endif // EXPENSIVECLASS_H
