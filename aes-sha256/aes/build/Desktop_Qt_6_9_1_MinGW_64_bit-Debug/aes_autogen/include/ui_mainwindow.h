/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QTextEdit *lineEditInput;
    QPushButton *pushButtonEncrypt;
    QTextEdit *lineEditOutput;
    QPushButton *pushButtonDecrypt;
    QTextEdit *lineEditHashInput;
    QPushButton *pushButtonHash;
    QTextEdit *lineEditHashOutput;
    QFrame *Line;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 751, 581));
        lineEditInput = new QTextEdit(groupBox);
        lineEditInput->setObjectName("lineEditInput");
        lineEditInput->setGeometry(QRect(70, 50, 621, 66));
        pushButtonEncrypt = new QPushButton(groupBox);
        pushButtonEncrypt->setObjectName("pushButtonEncrypt");
        pushButtonEncrypt->setGeometry(QRect(70, 140, 621, 41));
        lineEditOutput = new QTextEdit(groupBox);
        lineEditOutput->setObjectName("lineEditOutput");
        lineEditOutput->setGeometry(QRect(70, 200, 621, 66));
        pushButtonDecrypt = new QPushButton(groupBox);
        pushButtonDecrypt->setObjectName("pushButtonDecrypt");
        pushButtonDecrypt->setGeometry(QRect(70, 280, 621, 41));
        lineEditHashInput = new QTextEdit(groupBox);
        lineEditHashInput->setObjectName("lineEditHashInput");
        lineEditHashInput->setGeometry(QRect(70, 350, 621, 66));
        pushButtonHash = new QPushButton(groupBox);
        pushButtonHash->setObjectName("pushButtonHash");
        pushButtonHash->setGeometry(QRect(70, 430, 621, 41));
        lineEditHashOutput = new QTextEdit(groupBox);
        lineEditHashOutput->setObjectName("lineEditHashOutput");
        lineEditHashOutput->setGeometry(QRect(70, 480, 621, 66));
        Line = new QFrame(groupBox);
        Line->setObjectName("Line");
        Line->setGeometry(QRect(0, 305, 751, 61));
        Line->setFrameShape(QFrame::Shape::HLine);
        Line->setFrameShadow(QFrame::Shadow::Sunken);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "AES & SHA-256", nullptr));
        pushButtonEncrypt->setText(QCoreApplication::translate("MainWindow", "Encrypt", nullptr));
        pushButtonDecrypt->setText(QCoreApplication::translate("MainWindow", "Decrypt", nullptr));
        pushButtonHash->setText(QCoreApplication::translate("MainWindow", "Hash ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
