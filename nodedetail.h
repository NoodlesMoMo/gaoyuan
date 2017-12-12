#ifndef NODEDETAIL_H
#define NODEDETAIL_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QGroupBox>

class NodeDetail : public QWidget
{
    Q_OBJECT

public:
    explicit NodeDetail(QWidget *parent = 0);

    void setText(const QString& text);

signals:

public slots:

private:
    QLCDNumber *m_input_i_lcd;
    QLCDNumber *m_input_v_lcd;
    QLCDNumber *m_output_i_lcd;
    QLCDNumber *m_output_v_lcd;
};

#endif // NODEDETAIL_H
