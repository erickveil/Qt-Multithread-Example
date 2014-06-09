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
    explicit MainClass(QObject *parent = 0);
    ~MainClass();
    bool runJob();

signals:

public slots:

private:
    QThread *thread;
    ExpensiveClass *worker;
};

#endif // MAINCLASS_H
