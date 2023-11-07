#include "widget.h"
#include"creatordialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //初始化tcp
    socket=new QTcpSocket(this);
    init();
    //如果连接服务器成功,该客户端就会发射一个connected的信号
    connect(socket,&QTcpSocket::connected,this,&Widget::connected_slot);
}

Widget::~Widget()
{
}

void Widget::init()
{
    auto pMenuBar=new QMenuBar(this);
    auto pViewMenu=pMenuBar->addMenu("View");
    auto pAbout=pMenuBar->addMenu("About");
    auto pCreatorAction=pViewMenu->addAction("Build");

    connect(pCreatorAction,&QAction::triggered,this,&Widget::openCreatorDialog);
}

void Widget::openCreatorDialog()
{
    CreatorDialog dialog(socket,this);
    dialog.setWindowTitle("liujun build");
    dialog.exec();

}

void Widget::connected_slot()
{
    QMessageBox::information(this,"success","connect success");
}

