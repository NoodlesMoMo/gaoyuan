#include "nodedetail.h"
#include <QHBoxLayout>
#include <QRadioButton>

const QString ErrorLogStyleSheet = "QTextEdit {" \
                                   "border: 1px solid rgb(45, 45, 45);"\
                                   "color: rgb(102, 255, 0);" \
                                   "font-size: 16px;" \
                                   "background: rgb(57, 58, 60);}";

const QString GYLabelStyleSheet = "QLabel{font-size: 26px;}";

const QString LCDStyleSheet = "QLCDNumber{border: 1px solid rgb(45, 45, 45);"\
        "border-radius: 4px;" \
        "color: rgb(255, 0, 0);" \
        "background: rgb(94, 107, 162); "\
        "}";

NodeDetail::NodeDetail(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QGroupBox *groupBox = new QGroupBox(tr(""));

    QLabel *input_v_lbl = new QLabel(QString::fromUtf8("输入电压 (V AC)"));
    QLabel *output_i_lbl = new QLabel(QString::fromUtf8("输出电流 ( A )"));
    QLabel *output_v_lbl = new QLabel(QString::fromUtf8("输出电压 (V DC)"));

    m_id_label = new QLabel;
    m_status_label = new QLabel;

    m_id_label->setStyleSheet("QLabel{font-size: 16px;}");
    m_status_label->setStyleSheet("QLabel{font-size: 16px;}");
    m_id_label->setScaledContents(true);
    m_status_label->setScaledContents(true);
    input_v_lbl->setStyleSheet(GYLabelStyleSheet);
    output_i_lbl->setStyleSheet(GYLabelStyleSheet);
    output_v_lbl->setStyleSheet(GYLabelStyleSheet);

    input_v_lbl->setAlignment(Qt::AlignCenter);
    output_i_lbl->setAlignment(Qt::AlignCenter);
    output_v_lbl->setAlignment(Qt::AlignCenter);
    m_id_label->setAlignment(Qt::AlignCenter);

    m_input_v_lcd = new QLCDNumber(6);
    m_output_i_lcd = new QLCDNumber(6);
    m_output_v_lcd = new QLCDNumber(6);

    m_input_v_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_output_i_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_output_v_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_input_v_lcd->setStyleSheet(LCDStyleSheet);
    m_output_i_lcd->setStyleSheet(LCDStyleSheet);
    m_output_v_lcd->setStyleSheet(LCDStyleSheet);

    QHBoxLayout *status_layout = new QHBoxLayout;
    QHBoxLayout *input_i_layout = new QHBoxLayout;
    QHBoxLayout *input_v_layout = new QHBoxLayout;
    QHBoxLayout *output_i_layout = new QHBoxLayout;
    QHBoxLayout *output_v_layout = new QHBoxLayout;

    status_layout->addWidget(m_id_label);
    status_layout->addWidget(m_status_label);

    input_v_layout->addWidget(input_v_lbl);
    input_v_layout->addWidget(m_input_v_lcd);

    output_i_layout->addWidget(output_i_lbl);
    output_i_layout->addWidget(m_output_i_lcd);

    output_v_layout->addWidget(output_v_lbl);
    output_v_layout->addWidget(m_output_v_lcd);

    QVBoxLayout *vbox = new QVBoxLayout;
    //vbox->addLayout(status_layout);
    vbox->addLayout(input_i_layout);
    vbox->addLayout(input_v_layout);
    vbox->addLayout(output_i_layout);
    vbox->addLayout(output_v_layout);
    groupBox->setLayout(vbox);
    groupBox->setMinimumHeight(300);

    QWidget *desc_widget = new QWidget;
    QFrame *line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    m_descEdit = new QTextEdit;
    m_descEdit->setReadOnly(true);
    m_descEdit->setStyleSheet(ErrorLogStyleSheet);
    QVBoxLayout *desc_layout = new QVBoxLayout(desc_widget);
    desc_layout->addWidget(m_descEdit);

    layout->addLayout(status_layout);
    layout->addWidget(groupBox);
    layout->addWidget(line);
    layout->addWidget(desc_widget);
}

void NodeDetail::errorLog(const QString id, const QString& log){
    m_descEdit->append(QString("<b>%1<b> <i>%2</i>").arg(id, log));
}

void NodeDetail::showGYData(const QString& id, const GYData &data) const
{
    m_id_label->setText(id);
    m_output_v_lcd->display(data.ac_v);
    m_output_i_lcd->display(data.dc_i);
    m_input_v_lcd->display(data.dc_v);

    if(data.faultBit == 0){
        m_status_label->setText(QString::fromUtf8("正常"));
    }else{
        m_status_label->setText(QString::fromUtf8("故障"));
    }
}
