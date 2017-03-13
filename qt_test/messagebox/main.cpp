#include "my_flag.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MessageBox* w;
    w = new MessageBox();
    w->show();

    return a.exec();
}
