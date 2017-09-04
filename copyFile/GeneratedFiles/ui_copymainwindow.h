/********************************************************************************
** Form generated from reading UI file 'copymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COPYMAINWINDOW_H
#define UI_COPYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CopyMainWindowClass
{
public:
    QWidget *centralWidget;
    QGroupBox *OriginBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *OriginLine;
    QPushButton *OriginButton;
    QGroupBox *TargetBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *TargetLine;
    QPushButton *TargetButton;
    QPushButton *copyButton;
    QPushButton *quitButton;
    QTextEdit *resultEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *closeButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CopyMainWindowClass)
    {
        if (CopyMainWindowClass->objectName().isEmpty())
            CopyMainWindowClass->setObjectName(QString::fromUtf8("CopyMainWindowClass"));
        CopyMainWindowClass->setEnabled(true);
        CopyMainWindowClass->resize(600, 400);
        centralWidget = new QWidget(CopyMainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        OriginBox = new QGroupBox(centralWidget);
        OriginBox->setObjectName(QString::fromUtf8("OriginBox"));
        OriginBox->setGeometry(QRect(20, 10, 251, 81));
        layoutWidget = new QWidget(OriginBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 216, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        OriginLine = new QLineEdit(layoutWidget);
        OriginLine->setObjectName(QString::fromUtf8("OriginLine"));

        horizontalLayout->addWidget(OriginLine);

        OriginButton = new QPushButton(layoutWidget);
        OriginButton->setObjectName(QString::fromUtf8("OriginButton"));

        horizontalLayout->addWidget(OriginButton);

        TargetBox = new QGroupBox(centralWidget);
        TargetBox->setObjectName(QString::fromUtf8("TargetBox"));
        TargetBox->setGeometry(QRect(290, 10, 251, 81));
        layoutWidget1 = new QWidget(TargetBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 20, 216, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        TargetLine = new QLineEdit(layoutWidget1);
        TargetLine->setObjectName(QString::fromUtf8("TargetLine"));

        horizontalLayout_2->addWidget(TargetLine);

        TargetButton = new QPushButton(layoutWidget1);
        TargetButton->setObjectName(QString::fromUtf8("TargetButton"));

        horizontalLayout_2->addWidget(TargetButton);

        copyButton = new QPushButton(centralWidget);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));
        copyButton->setGeometry(QRect(300, 300, 75, 23));
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(390, 300, 75, 23));
        resultEdit = new QTextEdit(centralWidget);
        resultEdit->setObjectName(QString::fromUtf8("resultEdit"));
        resultEdit->setGeometry(QRect(40, 150, 511, 131));
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(40, 100, 96, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        spinBox = new QSpinBox(layoutWidget2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setValue(10);

        horizontalLayout_3->addWidget(spinBox);

        closeButton = new QPushButton(centralWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(480, 300, 75, 23));
        CopyMainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CopyMainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        CopyMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CopyMainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CopyMainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CopyMainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CopyMainWindowClass->setStatusBar(statusBar);

        retranslateUi(CopyMainWindowClass);

        QMetaObject::connectSlotsByName(CopyMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *CopyMainWindowClass)
    {
        CopyMainWindowClass->setWindowTitle(QApplication::translate("CopyMainWindowClass", "\345\244\215\345\210\266\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        OriginBox->setTitle(QApplication::translate("CopyMainWindowClass", "\345\216\237\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        OriginButton->setText(QApplication::translate("CopyMainWindowClass", "\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        TargetBox->setTitle(QApplication::translate("CopyMainWindowClass", "\347\233\256\346\240\207\350\267\257\345\276\204", 0, QApplication::UnicodeUTF8));
        TargetButton->setText(QApplication::translate("CopyMainWindowClass", "\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        copyButton->setText(QApplication::translate("CopyMainWindowClass", "\345\244\215\345\210\266", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("CopyMainWindowClass", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CopyMainWindowClass", "\347\272\277\347\250\213\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("CopyMainWindowClass", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CopyMainWindowClass: public Ui_CopyMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COPYMAINWINDOW_H
