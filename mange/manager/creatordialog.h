#ifndef CREATORDIALOG_H
#define CREATORDIALOG_H

#include <QDialog>
#include<QPushButton>
#include<QTcpSocket>
#include"configwidget.h"
class CreatorDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CreatorDialog(QTcpSocket* socket,QWidget *parent = nullptr);

signals:

protected slots:
    void onConnectButtonClicked();
    void onExitButtonClicked();
    void handleSocketError(QAbstractSocket::SocketError error);

private:
    QTcpSocket* m_socket;
    ConfigWidget* m_pConfigWidget;
    QPushButton* m_pConnectButton;
    QPushButton* m_pExitButton;
};

#endif // CREATORDIALOG_H
