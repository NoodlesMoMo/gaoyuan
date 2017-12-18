#include "work_thread.h"
#include <unistd.h>
#include <QFile>
#include <QDebug>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

const char* swan_fifo_path = "/var/gaoyuan_broker/input";
const int max_buf_length = 4096;

void Worker::doWork(const QString &data)
{
    Q_UNUSED(data);

    /*
    if(data != "start"){
        isRunning = false;
        return;
    }

    int fifo = open(swan_fifo_path, O_RDONLY);
    if(fifo < 0){
        perror("open fifo error:");
        return;
    }
    char buf[max_buf_length];

    while(isRunning){
        memset(buf, 0, max_buf_length);
        read(fifo, buf, max_buf_length);
        qDebug() << QString(buf);

        emit resultReady(QString(buf));
    }
    */
}

void Worker::stop(const QString &data)
{
    if(data == "stop"){
        isRunning = false;
    }
}

void Controller::handleResults(const QString &result)
{
    emit resultRelay(result);
}
