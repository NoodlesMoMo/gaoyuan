#include "gylogger.h"
#include <QDateTime>
#include <QFile>
#include <QMutex>
#include <QDir>
#include <QTextStream>

QFile *_gyLog;
QMutex *_mutex;
QTextStream *_textStream;

void openLog()
{
    QDir dir;
    QString path = QDir::currentPath() + QDir::separator() + "log";
    if(!dir.exists(path)){
        dir.mkdir(path);
    }

    QString fileName = QString("gaoyuan_%1.log").arg(QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));
    _gyLog = new QFile(path + QDir::separator() +fileName);
    _gyLog->open(QIODevice::WriteOnly|QIODevice::Append);
    _mutex = new QMutex;
}

void writeLog(QString& log)
{
    _mutex->lock();

    QTextStream(_gyLog) << log << endl;
    _gyLog->flush();

    _mutex->unlock();
}

void closeLog()
{
    _gyLog->close();
    delete _gyLog;
    delete _mutex;
}

