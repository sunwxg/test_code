#ifndef MY_FLAG_H
#define MY_FLAG_H

#include <QMainWindow>
#include "ui_my_flag.h"

#include <X11/extensions/XInput.h>
#include <QX11Info>

//namespace Ui {
	//class my_flag;
//}

bool isPressed(XDeviceState *state);

class my_flag : public QMainWindow
{
    Q_OBJECT

public:
    explicit my_flag(QWidget *parent = 0);
    ~my_flag();

signals:

  void sendWordToMainWindow( QString const & word );

private:
    Ui::my_flag ui;
    Display * display;

    void hideWindow();
    bool isButtonPressed();

private slots:
	void pushButtonClicked();

};

#endif // MY_FLAG_H
