/********************************************************************************
** Form generated from reading UI file 'simplemergerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEMERGERWINDOW_H
#define UI_SIMPLEMERGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimpleMergerWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *fileOneButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *fileOneLabel;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *fileTwoButton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *fileTwoLabel;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *outFileButton;
    QSpacerItem *horizontalSpacer_4;
    QLabel *outFileLabel;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *comparedColumnEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *fileOneColumnsEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *fileTwoColumnsEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *mergeButton;
    QPushButton *viewButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SimpleMergerWindow)
    {
        if (SimpleMergerWindow->objectName().isEmpty())
            SimpleMergerWindow->setObjectName(QStringLiteral("SimpleMergerWindow"));
        SimpleMergerWindow->resize(400, 355);
        centralWidget = new QWidget(SimpleMergerWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        fileOneButton = new QPushButton(centralWidget);
        fileOneButton->setObjectName(QStringLiteral("fileOneButton"));

        horizontalLayout_2->addWidget(fileOneButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        fileOneLabel = new QLabel(centralWidget);
        fileOneLabel->setObjectName(QStringLiteral("fileOneLabel"));

        horizontalLayout_2->addWidget(fileOneLabel);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        fileTwoButton = new QPushButton(centralWidget);
        fileTwoButton->setObjectName(QStringLiteral("fileTwoButton"));

        horizontalLayout_3->addWidget(fileTwoButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        fileTwoLabel = new QLabel(centralWidget);
        fileTwoLabel->setObjectName(QStringLiteral("fileTwoLabel"));

        horizontalLayout_3->addWidget(fileTwoLabel);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        outFileButton = new QPushButton(centralWidget);
        outFileButton->setObjectName(QStringLiteral("outFileButton"));

        horizontalLayout_5->addWidget(outFileButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        outFileLabel = new QLabel(centralWidget);
        outFileLabel->setObjectName(QStringLiteral("outFileLabel"));

        horizontalLayout_5->addWidget(outFileLabel);


        gridLayout->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        comparedColumnEdit = new QLineEdit(centralWidget);
        comparedColumnEdit->setObjectName(QStringLiteral("comparedColumnEdit"));

        verticalLayout->addWidget(comparedColumnEdit);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        fileOneColumnsEdit = new QLineEdit(centralWidget);
        fileOneColumnsEdit->setObjectName(QStringLiteral("fileOneColumnsEdit"));

        verticalLayout_2->addWidget(fileOneColumnsEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        fileTwoColumnsEdit = new QLineEdit(centralWidget);
        fileTwoColumnsEdit->setObjectName(QStringLiteral("fileTwoColumnsEdit"));

        verticalLayout_3->addWidget(fileTwoColumnsEdit);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(208, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        mergeButton = new QPushButton(centralWidget);
        mergeButton->setObjectName(QStringLiteral("mergeButton"));
        mergeButton->setEnabled(false);

        horizontalLayout_4->addWidget(mergeButton);

        viewButton = new QPushButton(centralWidget);
        viewButton->setObjectName(QStringLiteral("viewButton"));
        viewButton->setEnabled(false);

        horizontalLayout_4->addWidget(viewButton);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        SimpleMergerWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SimpleMergerWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 19));
        SimpleMergerWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SimpleMergerWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SimpleMergerWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SimpleMergerWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SimpleMergerWindow->setStatusBar(statusBar);

        retranslateUi(SimpleMergerWindow);

        QMetaObject::connectSlotsByName(SimpleMergerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SimpleMergerWindow)
    {
        SimpleMergerWindow->setWindowTitle(QApplication::translate("SimpleMergerWindow", "Simple Merger", 0));
        fileOneButton->setText(QApplication::translate("SimpleMergerWindow", "File &One:", 0));
        fileOneLabel->setText(QApplication::translate("SimpleMergerWindow", "<No file selected>", 0));
        fileTwoButton->setText(QApplication::translate("SimpleMergerWindow", "File &Two:", 0));
        fileTwoLabel->setText(QApplication::translate("SimpleMergerWindow", "<No file selected>", 0));
        outFileButton->setText(QApplication::translate("SimpleMergerWindow", "Out &File:", 0));
        outFileLabel->setText(QApplication::translate("SimpleMergerWindow", "<No file selected>", 0));
        label->setText(QApplication::translate("SimpleMergerWindow", "Merge column", 0));
#ifndef QT_NO_TOOLTIP
        comparedColumnEdit->setToolTip(QApplication::translate("SimpleMergerWindow", "Enter the column used to match entries in the two input files (NOTE: Column one starts at 0).", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("SimpleMergerWindow", "File 1 columns:", 0));
#ifndef QT_NO_TOOLTIP
        fileOneColumnsEdit->setToolTip(QApplication::translate("SimpleMergerWindow", "Enter the column(s) you wish to merge from file 1 (NOTE: Column one starts at 0).", 0));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("SimpleMergerWindow", "File 2 columns:", 0));
#ifndef QT_NO_TOOLTIP
        fileTwoColumnsEdit->setToolTip(QApplication::translate("SimpleMergerWindow", "Enter the column(s) you wish to merge from file 1 (NOTE: Column one starts at 0).", 0));
#endif // QT_NO_TOOLTIP
        mergeButton->setText(QApplication::translate("SimpleMergerWindow", "Merge", 0));
        viewButton->setText(QApplication::translate("SimpleMergerWindow", "View", 0));
    } // retranslateUi

};

namespace Ui {
    class SimpleMergerWindow: public Ui_SimpleMergerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEMERGERWINDOW_H
