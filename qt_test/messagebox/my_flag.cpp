#include <QCursor>
#include <stdio.h>
#include "my_flag.h"
#include "ui_my_flag.h"

MessageBox::MessageBox(QWidget *parent)
    //QMainWindow(parent)
    //ui(new Ui::MessageBox)
{
    ui.setupUi(this);

  setWindowFlags( Qt::Tool
    | Qt::FramelessWindowHint
    | Qt::WindowStaysOnTopHint
    //Qt::WindowSystemMenuHint |
    //Qt::ToolTip | Qt::FramelessWindowHint |
    //| Qt::WindowDoesNotAcceptFocus
    //| Qt::WindowTransparentForInput
	    //Qt::NoDropShadowWindowHint );
    );

  //setAttribute(Qt::WA_ShowWithoutActivating);
  setAttribute(Qt::WA_X11DoNotAcceptFocus);

    connect( ui.pushButton, SIGNAL( clicked( bool ) ),
		this, SLOT( pushButtonClicked() ) );
}

MessageBox::~MessageBox()
{
    //delete ui;
}

void MessageBox::pushButtonClicked()
{
  static int x = 0;

  x = x + 10;

  printf("x=%d\n", x);
  move( x, x );

  //hideWindow();
}

void MessageBox::hideWindow()
{
  hide();
}
