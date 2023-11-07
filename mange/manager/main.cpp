#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/1.png"));
    Widget w;
    w.setWindowTitle("人力资源管理系统");
    w.resize(850,750);
    w.show();
    return a.exec();
}
