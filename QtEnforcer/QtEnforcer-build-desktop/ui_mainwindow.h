/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Mar 20 01:42:55 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QPushButton *selSnowballBtn;
    QSpacerItem *horizontalSpacer;
    QLabel *snowballLabel;
    QPushButton *selTargetBtn;
    QSpacerItem *horizontalSpacer_2;
    QLabel *targetLabel;
    QGridLayout *gridLayout_2;
    QLineEdit *comparedColumnsEdit;
    QLabel *matchingLabel;
    QLineEdit *requiredMatchesEdit;
    QLabel *compareLabel;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QLabel *appendModeLabel;
    QRadioButton *appendSameRowRadio;
    QRadioButton *appendSeparateRowsRadio;
    QSpacerItem *verticalSpacer;
    QPushButton *actionButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(565, 285);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 1, 551, 231));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        selSnowballBtn = new QPushButton(widget);
        selSnowballBtn->setObjectName(QString::fromUtf8("selSnowballBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(selSnowballBtn->sizePolicy().hasHeightForWidth());
        selSnowballBtn->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(9);
        selSnowballBtn->setFont(font);

        gridLayout->addWidget(selSnowballBtn, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        snowballLabel = new QLabel(widget);
        snowballLabel->setObjectName(QString::fromUtf8("snowballLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(snowballLabel->sizePolicy().hasHeightForWidth());
        snowballLabel->setSizePolicy(sizePolicy2);
        snowballLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(snowballLabel, 0, 2, 1, 1);

        selTargetBtn = new QPushButton(widget);
        selTargetBtn->setObjectName(QString::fromUtf8("selTargetBtn"));
        selTargetBtn->setFont(font);

        gridLayout->addWidget(selTargetBtn, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        targetLabel = new QLabel(widget);
        targetLabel->setObjectName(QString::fromUtf8("targetLabel"));
        sizePolicy2.setHeightForWidth(targetLabel->sizePolicy().hasHeightForWidth());
        targetLabel->setSizePolicy(sizePolicy2);
        targetLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(targetLabel, 1, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comparedColumnsEdit = new QLineEdit(widget);
        comparedColumnsEdit->setObjectName(QString::fromUtf8("comparedColumnsEdit"));

        gridLayout_2->addWidget(comparedColumnsEdit, 0, 1, 1, 1);

        matchingLabel = new QLabel(widget);
        matchingLabel->setObjectName(QString::fromUtf8("matchingLabel"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        matchingLabel->setFont(font1);

        gridLayout_2->addWidget(matchingLabel, 1, 0, 1, 1);

        requiredMatchesEdit = new QLineEdit(widget);
        requiredMatchesEdit->setObjectName(QString::fromUtf8("requiredMatchesEdit"));

        gridLayout_2->addWidget(requiredMatchesEdit, 1, 1, 1, 1);

        compareLabel = new QLabel(widget);
        compareLabel->setObjectName(QString::fromUtf8("compareLabel"));
        compareLabel->setFont(font1);

        gridLayout_2->addWidget(compareLabel, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        appendModeLabel = new QLabel(widget);
        appendModeLabel->setObjectName(QString::fromUtf8("appendModeLabel"));
        appendModeLabel->setFont(font1);
        appendModeLabel->setTextFormat(Qt::AutoText);
        appendModeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(appendModeLabel);

        appendSameRowRadio = new QRadioButton(widget);
        appendSameRowRadio->setObjectName(QString::fromUtf8("appendSameRowRadio"));
        QFont font2;
        font2.setPointSize(10);
        appendSameRowRadio->setFont(font2);
        appendSameRowRadio->setChecked(true);

        verticalLayout->addWidget(appendSameRowRadio);

        appendSeparateRowsRadio = new QRadioButton(widget);
        appendSeparateRowsRadio->setObjectName(QString::fromUtf8("appendSeparateRowsRadio"));
        appendSeparateRowsRadio->setFont(font2);

        verticalLayout->addWidget(appendSeparateRowsRadio);


        gridLayout_3->addLayout(verticalLayout, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 0, 1, 1);

        actionButton = new QPushButton(widget);
        actionButton->setObjectName(QString::fromUtf8("actionButton"));
        actionButton->setEnabled(false);

        gridLayout_3->addWidget(actionButton, 3, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 565, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QtEnforcer", 0, QApplication::UnicodeUTF8));
        selSnowballBtn->setText(QApplication::translate("MainWindow", "Select Snowball file...", 0, QApplication::UnicodeUTF8));
        snowballLabel->setText(QApplication::translate("MainWindow", "--", 0, QApplication::UnicodeUTF8));
        selTargetBtn->setText(QApplication::translate("MainWindow", "Select target file...", 0, QApplication::UnicodeUTF8));
        targetLabel->setText(QApplication::translate("MainWindow", "--", 0, QApplication::UnicodeUTF8));
        matchingLabel->setText(QApplication::translate("MainWindow", "Matching columns:", 0, QApplication::UnicodeUTF8));
        compareLabel->setText(QApplication::translate("MainWindow", "Compared columns:", 0, QApplication::UnicodeUTF8));
        appendModeLabel->setText(QApplication::translate("MainWindow", "Append mode", 0, QApplication::UnicodeUTF8));
        appendSameRowRadio->setText(QApplication::translate("MainWindow", "Same row", 0, QApplication::UnicodeUTF8));
        appendSeparateRowsRadio->setText(QApplication::translate("MainWindow", "Separate rows", 0, QApplication::UnicodeUTF8));
        actionButton->setText(QApplication::translate("MainWindow", "Scan", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
