#ifndef GYLOGGER_H
#define GYLOGGER_H

#include <QtMsgHandler>
#include <QString>

void openLog();
void writeLog(QString& log);
void closeLog();

#endif // GYLOGGER_H
