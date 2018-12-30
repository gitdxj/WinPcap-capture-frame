/********************************************************************************
** Form generated from reading UI file 'na_qt_test1.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NA_QT_TEST1_H
#define UI_NA_QT_TEST1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NA_Qt_test1Class
{
public:
    QWidget *centralWidget;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *AdapterList;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextBrowser *AdapterInfo;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *startButton;
    QPushButton *stopButton;
    QTextBrowser *CaptureInfo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NA_Qt_test1Class)
    {
        if (NA_Qt_test1Class->objectName().isEmpty())
            NA_Qt_test1Class->setObjectName(QStringLiteral("NA_Qt_test1Class"));
        NA_Qt_test1Class->resize(794, 670);
        centralWidget = new QWidget(NA_Qt_test1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(0, 0, 791, 621));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        AdapterList = new QListWidget(layoutWidget);
        AdapterList->setObjectName(QStringLiteral("AdapterList"));

        verticalLayout->addWidget(AdapterList);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        AdapterInfo = new QTextBrowser(layoutWidget);
        AdapterInfo->setObjectName(QStringLiteral("AdapterInfo"));

        verticalLayout_2->addWidget(AdapterInfo);


        horizontalLayout->addLayout(verticalLayout_2);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        startButton = new QPushButton(layoutWidget1);
        startButton->setObjectName(QStringLiteral("startButton"));

        horizontalLayout_2->addWidget(startButton);

        stopButton = new QPushButton(layoutWidget1);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        horizontalLayout_2->addWidget(stopButton);

        splitter->addWidget(layoutWidget1);
        CaptureInfo = new QTextBrowser(splitter);
        CaptureInfo->setObjectName(QStringLiteral("CaptureInfo"));
        splitter->addWidget(CaptureInfo);
        NA_Qt_test1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NA_Qt_test1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 794, 26));
        NA_Qt_test1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NA_Qt_test1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NA_Qt_test1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(NA_Qt_test1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NA_Qt_test1Class->setStatusBar(statusBar);

        retranslateUi(NA_Qt_test1Class);

        QMetaObject::connectSlotsByName(NA_Qt_test1Class);
    } // setupUi

    void retranslateUi(QMainWindow *NA_Qt_test1Class)
    {
        NA_Qt_test1Class->setWindowTitle(QApplication::translate("NA_Qt_test1Class", "NA_Qt_test1", 0));
        label->setText(QApplication::translate("NA_Qt_test1Class", "device list:", 0));
        label_2->setText(QApplication::translate("NA_Qt_test1Class", "device information:", 0));
        label_3->setText(QApplication::translate("NA_Qt_test1Class", "captured packet:", 0));
        startButton->setText(QApplication::translate("NA_Qt_test1Class", "start", 0));
        stopButton->setText(QApplication::translate("NA_Qt_test1Class", "stop", 0));
    } // retranslateUi

};

namespace Ui {
    class NA_Qt_test1Class: public Ui_NA_Qt_test1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NA_QT_TEST1_H
