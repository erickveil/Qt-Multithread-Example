#ifndef MAINCLASS_H
#define MAINCLASS_H
#include <QThread>
#include <iostream>
#include "expensiveclass.h"

using namespace std;


#include "expensiveclass.h"

#include <QObject>

class MainClass : public QObject
{
    Q_OBJECT
public:
    QString value_for_lock;

    explicit MainClass(QObject *parent = 0);
    ~MainClass();
    bool runJob();

signals:

public slots:
    void slotCrossThread(QString data);

private:
    QThread *thread;
    ExpensiveClass *worker;
    QString _value_for_signal;
};

#endif // MAINCLASS_H
