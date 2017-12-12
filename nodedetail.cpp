#include "nodedetail.h"
#include <QHBoxLayout>
#include <QRadioButton>

NodeDetail::NodeDetail(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QGroupBox *groupBox = new QGroupBox(tr("device data"));

    QLabel *input_i_lbl = new QLabel(QString::fromUtf8("输入电流"));
    QLabel *input_v_lbl = new QLabel(QString::fromUtf8("输入电压"));
    QLabel *output_i_lbl = new QLabel(QString::fromUtf8("输出电压"));
    QLabel *output_v_lbl = new QLabel(QString::fromUtf8("输出电压"));

    m_input_i_lcd = new QLCDNumber(5);
    m_input_v_lcd = new QLCDNumber(5);
    m_output_i_lcd = new QLCDNumber(5);
    m_output_v_lcd = new QLCDNumber(5);

    QHBoxLayout *input_i_layout = new QHBoxLayout;
    QHBoxLayout *input_v_layout = new QHBoxLayout;
    QHBoxLayout *output_i_layout = new QHBoxLayout;
    QHBoxLayout *output_v_layout = new QHBoxLayout;

    input_i_layout->addWidget(input_i_lbl);
    input_i_layout->addWidget(m_input_i_lcd);

    input_v_layout->addWidget(input_v_lbl);
    input_v_layout->addWidget(m_input_v_lcd);

    output_i_layout->addWidget(output_i_lbl);
    output_i_layout->addWidget(m_output_i_lcd);

    output_v_layout->addWidget(output_v_lbl);
    output_v_layout->addWidget(m_output_v_lcd);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addLayout(input_i_layout);
    vbox->addLayout(input_v_layout);
    vbox->addLayout(output_i_layout);
    vbox->addLayout(output_v_layout);
    groupBox->setLayout(vbox);

    layout->addWidget(groupBox);

    QWidget *desc_widget = new QWidget;
    QFrame *line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    m_description = new QLabel("TODO: add description here ...");
    QVBoxLayout *desc_layout = new QVBoxLayout(desc_widget);
    desc_layout->addWidget(m_description);

    layout->addWidget(line);
    layout->addWidget(desc_widget);
}

void NodeDetail::setText(const QString &text)
{

}

