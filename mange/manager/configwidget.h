#ifndef CONFIGWIDGET_H
#define CONFIGWIDGET_H

#include <QObject>
#include <QTabWidget>
#include<QLineEdit>
#include"userwidget.h"
class ConfigWidget:public QTabWidget
{
    Q_OBJECT
public:
    ConfigWidget(QWidget* parent=nullptr);
    QString getUserName() const;
    QString getUserPassword() const;
    QString getServerIp() const;
private:
    QWidget* createForwardWidget();


private:
    QLineEdit* m_pTargetEdit;
    UserWidget* m_pUser;
    QLineEdit* m_pUserName;
    QLineEdit* m_pUserPassword;
};

#endif // CONFIGWIDGET_H
