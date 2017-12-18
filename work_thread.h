#ifndef WORK_THREAD_H
#define WORK_THREAD_H

#include <QObject>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT

public:
    Worker(): isRunning(true){}

public slots:
    void doWork(const QString &data);
    void stop(const QString &data);

signals:
    void resultReady(const QString &result);

private:
    bool isRunning;
};

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller()
    {
        Worker *worker = new Worker;
        worker->moveToThread(&workerThread);
        connect(&workerThread, SIGNAL(finished()), worker, SLOT(deleteLater()));
        connect(this, SIGNAL(operate(QString)), worker, SLOT(doWork(QString)));
        connect(this, SIGNAL(operate(QString)), worker, SLOT(stop(QString)));
        connect(worker, SIGNAL(resultReady(QString)), this, SLOT(handleResults(QString)));
        workerThread.start();
    }

    ~Controller() {
        workerThread.quit();
        workerThread.wait();
    }

    void start(){ emit operate("start"); }
    void stop(){ emit operate("stop"); }

public slots:
    void handleResults(const QString &);

signals:
    void operate(const QString &);
    void resultRelay(const QString &result);

private:
    QThread workerThread;
};

#endif
