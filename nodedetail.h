#ifndef NODEDETAIL_H
#define NODEDETAIL_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QGroupBox>
#include <QFrame>
#include <QWidget>
#include <QTextEdit>

#include "gydata.h"

class NodeDetail : public QWidget
{
    Q_OBJECT

public:
    explicit NodeDetail(QWidget *parent = 0);

    void errorLog(const QString id, const QString& log);

    void showGYData(const QString&, const GYData& data) const;

signals:

public slots:

private:
    QLCDNumber *m_input_v_lcd;
    QLCDNumber *m_output_i_lcd;
    QLCDNumber *m_output_v_lcd;

    QLabel *m_id_label;
    QLabel *m_status_label;

    QTextEdit *m_descEdit;
};

#endif // NODEDETAIL_H
