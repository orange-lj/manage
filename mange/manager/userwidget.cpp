#include "userwidget.h"
#include "qboxlayout.h"

UserWidget::UserWidget(QWidget *parent)
    : QWidget{parent}
{
    setContentsMargins(0,0,0,0);
    QHBoxLayout* pMainLayout=new QHBoxLayout(this);
    pMainLayout->setContentsMargins(0,0,0,0);
    m_pUser=new QComboBox(this);
    m_pUser->addItem("root");
    m_pUser->addItem("normal");
    pMainLayout->addWidget(m_pUser);

}
