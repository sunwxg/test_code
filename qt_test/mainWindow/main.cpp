#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>

class Application : public QApplication
{
public:
    Application(int &argc, char ** argv);

    // ~MyApplication();
private:
    bool notify(QObject *receiver, QEvent *event)
    {
	printf("notify: event type is %d\n", event->type());
        return QCoreApplication::notify(receiver, event);
    }
};

Application::Application(int &argc, char ** argv):
	QApplication(argc, argv)
{}

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    //QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
