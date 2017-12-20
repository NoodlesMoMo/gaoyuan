#include "gylogger.h"
#include <QDateTime>
#include <QFile>
#include <QMutex>
#include <QTextStream>

QFile *_gyLog;
QMutex *_mutex;
QTextStream *_textStream;

void openLog()
{
    QString fileName = QString("gaoyuan_%1.log").arg(QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss"));
    _gyLog = new QFile(fileName);
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

