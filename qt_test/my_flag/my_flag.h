#ifndef MY_FLAG_H
#define MY_FLAG_H

#include <QMainWindow>
#include "ui_my_flag.h"

//namespace Ui {
	//class my_flag;
//}

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

    void hideWindow();

private slots:
	void pushButtonClicked();

};

#endif // MY_FLAG_H
