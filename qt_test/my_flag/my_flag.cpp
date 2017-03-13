#include <QCursor>
#include <stdio.h>
#include "my_flag.h"
#include "ui_my_flag.h"

static Qt::WindowFlags popupWindowFlags =

#ifdef Q_WS_WIN
Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint
#else
Qt::Popup
#endif
;

my_flag::my_flag(QWidget *parent) :
    QMainWindow(parent)
    //ui(new Ui::my_flag)
{
    ui.setupUi(this);

    setWindowFlags( popupWindowFlags );

    connect( ui.pushButton, SIGNAL( clicked( bool ) ),
		this, SLOT( pushButtonClicked() ) );
}

my_flag::~my_flag()
{
    //delete ui;
}

void my_flag::pushButtonClicked()
{
  static int x = 0;

  x = x + 10;

  printf("x=%d\n", x);
  move( x, x );

  //hideWindow();
}

void my_flag::hideWindow()
{
  hide();
}
