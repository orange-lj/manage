#include "configwidget.h"
#include "qboxlayout.h"
#include <QLabel>
ConfigWidget::ConfigWidget(QWidget* parent)
{
    setContentsMargins(0,0,0,0);
    QWidget* pForwardWidget=createForwardWidget();
    addTab(pForwardWidget,"connect mode");
}

QString ConfigWidget::getUserName() const
{
    return m_pUserName->text();
}

QString ConfigWidget::getUserPassword() const
{
    return m_pUserPassword->text();
}

QString ConfigWidget::getServerIp() const
{
    return m_pTargetEdit->text();
}

QWidget *ConfigWidget::createForwardWidget()
{
    QWidget* pWidget=new QWidget();
    QVBoxLayout* pMainLayout=new QVBoxLayout(pWidget);
    QGridLayout* pGridLayout=new QGridLayout();
    pMainLayout->addLayout(pGridLayout);

    pGridLayout->addWidget(new QLabel("Server Address:"),0,0);
    m_pTargetEdit=new QLineEdit();
    pGridLayout->addWidget(m_pTargetEdit,0,1);

    pGridLayout->addWidget(new QLabel("choose:"),1,0);
    m_pUser=new UserWidget(pWidget);
    pGridLayout->addWidget(m_pUser,1,1);

    pGridLayout->addWidget(new QLabel("username:"),2,0);
    m_pUserName=new QLineEdit();
    pGridLayout->addWidget(m_pUserName,2,1);

    pGridLayout->addWidget(new QLabel("password:"),3,0);
    m_pUserPassword=new QLineEdit();
    pGridLayout->addWidget(m_pUserPassword,3,1);
    return pWidget;
}
