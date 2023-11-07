#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QMenuBar>
#include<QTcpSocket>
#include<QMessageBox>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void init();

private slots:
    void openCreatorDialog();

    void connected_slot();
private:
    //定义一个客户端指针
    QTcpSocket* socket;
};
#endif // WIDGET_H
