#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <QComboBox>
class UserWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UserWidget(QWidget *parent = nullptr);

signals:
private:
    QComboBox* m_pUser;
};

#endif // USERWIDGET_H
