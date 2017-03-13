#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    installEventFilter( this  );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent( QMouseEvent * ev )
{

  printf("mousePressEvent\n");
  //if ( ev->button() == Qt::LeftButton )
  //{
    //startPos = ev->globalPos();
    //setCursor( Qt::ClosedHandCursor );
  //}

  QMainWindow::mousePressEvent( ev );
}

bool MainWindow::eventFilter( QObject * watched, QEvent * event )
{
  //printf("event type is %d\n", event->type());
  //if ( mouseIntercepted )
  //{
    //// We're only interested in our events

    //if ( event->type() == QEvent::MouseMove )
    //{
////    DPRINTF( "Object: %s\n", watched->objectName().toUtf8().data() );
      //QMouseEvent * mouseEvent = ( QMouseEvent * ) event;
      //reactOnMouseMove( mouseEvent->globalPos() );
    //}
  //}

  return QMainWindow::eventFilter( watched, event );
}

//bool MainWindow::notify (QObject *receiver,QEvent *event ) {
  //printf("notify: event type is %d\n", event->type());
  //return QMainWindow::notify(receiver, event);
//}

