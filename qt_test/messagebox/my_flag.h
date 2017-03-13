#ifndef MY_FLAG_H
#define MY_FLAG_H

#include <QMainWindow>
#include "ui_my_flag.h"

//namespace Ui {
	//class my_flag;
//}

class MessageBox : public QMainWindow
{
    Q_OBJECT

public:
    explicit MessageBox(QWidget *parent = 0);
    ~MessageBox();

signals:

private:
    Ui::MessageBox ui;

    void hideWindow();

private slots:
	void pushButtonClicked();

};

#endif // MY_FLAG_H
