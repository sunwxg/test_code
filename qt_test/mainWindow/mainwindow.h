#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

  virtual void mousePressEvent( QMouseEvent * );
  virtual bool eventFilter( QObject * watched, QEvent * event );
  //bool notify (QObject *receiver, QEvent *event );
};

#endif // MAINWINDOW_H
