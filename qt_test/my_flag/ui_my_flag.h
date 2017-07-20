/********************************************************************************
** Form generated from reading UI file 'my_flag.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY_FLAG_H
#define UI_MY_FLAG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_my_flag
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;

    void setupUi(QMainWindow *my_flag)
    {
        if (my_flag->objectName().isEmpty())
            my_flag->setObjectName(QString::fromUtf8("my_flag"));
        my_flag->resize(30, 30);
        centralwidget = new QWidget(my_flag);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8("programicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        my_flag->setCentralWidget(centralwidget);

        retranslateUi(my_flag);

        QMetaObject::connectSlotsByName(my_flag);
    } // setupUi

    void retranslateUi(QMainWindow *my_flag)
    {
        my_flag->setWindowTitle(QApplication::translate("my_flag", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class my_flag: public Ui_my_flag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_FLAG_H
