#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	QWidget window;

	window.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	window.resize(30, 30);
	window.show();
	return app.exec();
}
