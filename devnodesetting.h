#ifndef DEVNODESETTING_H
#define DEVNODESETTING_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

struct NodeSetting{
    QString ip;
    QString port;
    QString desc;

    QString id(){
        return QString("%1:%2").arg(ip, port);
    }
};

class DevNodeSetting : public QDialog
{
    Q_OBJECT

public:
    DevNodeSetting(QWidget* parent=0);

    const NodeSetting& getSetting() const;

protected:
    QSize sizeHint() const;

protected slots:
    void onOkClick();
    void onCancleClick();

signals:
    void settingConfirm(const NodeSetting&);

private:
    QLineEdit *m_ip;
    QLineEdit *m_port;
    QLineEdit *m_description;
    QPushButton *m_ok_btn;
    QPushButton *m_cancle_btn;

    NodeSetting m_setting;
    bool m_is_ok;
};

#endif // DEVNODESETTING_H
