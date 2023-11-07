#include "creatordialog.h"
#include<QVBoxLayout>
#include<QMessageBox>
CreatorDialog::CreatorDialog(QTcpSocket* socket,QWidget *parent)
    : QDialog(parent),m_socket(socket)
{
    setWindowTitle("Connect");
    QVBoxLayout* pMainLayout=new QVBoxLayout(this);
    m_pConfigWidget=new ConfigWidget(this);
    pMainLayout->addWidget(m_pConfigWidget);

    m_pConnectButton=new QPushButton("connect");
    m_pExitButton=new QPushButton("exit");
    QHBoxLayout* pHBox=new QHBoxLayout();
    pMainLayout->addLayout(pHBox);
    pHBox->addWidget(m_pConnectButton);
    pHBox->addWidget(m_pExitButton);
    connect(m_pConnectButton,&QPushButton::clicked,this,&CreatorDialog::onConnectButtonClicked);
    connect(m_pExitButton,&QPushButton::clicked,this,&CreatorDialog::onExitButtonClicked);

}

void CreatorDialog::onConnectButtonClicked()
{
    //获取用户输入的用户名
    QString userName=m_pConfigWidget->getUserName();
    //获取用户输入的密码
    QString userPass=m_pConfigWidget->getUserPassword();
    //获取用户输入的服务端IP地址
    QString serverIp=m_pConfigWidget->getServerIp();
    quint16 port=8080;
    m_socket->connectToHost(serverIp,port);
    // 连接错误处理
    connect(m_socket, &QTcpSocket::errorOccurred, this, &CreatorDialog::handleSocketError);
}

void CreatorDialog::handleSocketError(QAbstractSocket::SocketError error)
{
    // 处理连接错误，显示错误信息
    QMessageBox::critical(this, "Connection Error", m_socket->errorString());
}

void CreatorDialog::onExitButtonClicked()
{
    this->close();
}
