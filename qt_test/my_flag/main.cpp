#include "my_flag.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    my_flag* w;
    w = new my_flag();
    w->show();

    return a.exec();
}
