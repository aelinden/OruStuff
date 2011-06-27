#include "simplemergerwindow.h"
#include "ui_simplemergerwindow.h"
#include <QStringList>
#include <QFileDialog>
#include <QDebug>
#include <QList>
#include "../FileProcessor/FileProcessor/fileprocessor.h"

SimpleMergerWindow::SimpleMergerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimpleMergerWindow)
{
    ui->setupUi(this);
    connect(ui->mergeButton, SIGNAL(clicked()), this, SLOT(slot_Merge()));
    connect(ui->fileOneButton, SIGNAL(clicked()), this, SLOT(slot_OpenFileOne()));
    connect(ui->fileTwoButton, SIGNAL(clicked()), this, SLOT(slot_OpenFileTwo()));
    connect(ui->fileOneColumnsEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_FileOneColumnsEditChanged(QString)));
    connect(ui->fileTwoColumnsEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_FileTwoColumnsEditChanged(QString)));
    connect(ui->matchColumnEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_MatchColumnEditChanged(QString)));
    connect(ui->outFileButton, SIGNAL(clicked()), this, SLOT(slot_SelectSaveFile()));
}

SimpleMergerWindow::~SimpleMergerWindow()
{
    delete ui;
}

// Signal the file processor to start
void SimpleMergerWindow::slot_Merge() {
    emit signal_StartProcess();
}

void SimpleMergerWindow::slot_OpenFileOne() {
    OpenFile(FileProcessor::FILE_ONE, QFileDialog::AcceptOpen);
}

void SimpleMergerWindow::slot_OpenFileTwo() {
    OpenFile(FileProcessor::FILE_TWO, QFileDialog::AcceptOpen);
}

/*
 * NOTE: Should probably be merged as much as possible with OpenFile below.
 * (See slot_OpenFileN above)
 */
void SimpleMergerWindow::slot_SelectSaveFile() {
    OpenFile(FileProcessor::OUT_FILE, QFileDialog::AcceptSave);
}

void SimpleMergerWindow::OpenFile(int fileId, QFileDialog::AcceptMode acceptMode) {
    QFileDialog *picker = new QFileDialog(this, Qt::Window);
    picker->setAcceptMode(acceptMode);
    QStringList picked;
    int dialogCode = picker->exec();
    picked = picker->selectedFiles();

    if(dialogCode == QFileDialog::Accepted) {
        emit signal_OpenFile(fileId, picked[0]);
    }
    else {
        qDebug() << "User cancelled file selection" << endl;
    }
    delete picker;
}


void SimpleMergerWindow::slot_FileOneColumnsEditChanged(const QString & s) {
    ColumnsEditChanged(s, FileProcessor::FILE_ONE);
}

void SimpleMergerWindow::slot_FileTwoColumnsEditChanged(const QString & s) {
    ColumnsEditChanged(s, FileProcessor::FILE_TWO);
}

void SimpleMergerWindow::slot_MatchColumnEditChanged(const QString & s) {
    emit signal_SetMatchColumn(s.toInt());
}

void SimpleMergerWindow::slot_FileOpened(int fileId, const QString & fileName) {
    switch(fileId) {
    case FileProcessor::FILE_ONE:
        ui->fileOneLabel->setText(fileName);
        fileOneOpened = true;
        break;
    case FileProcessor::FILE_TWO:
        ui->fileTwoLabel->setText(fileName);
        fileTwoOpened = true;
        break;
    case FileProcessor::OUT_FILE:
        ui->outFileLabel->setText(fileName);
        outFileOpened = true;
        break;
    default:
        qDebug() << tr("File with strange fileId opened. You should not be here!") << endl;
    }
    ActivateMergeButton();
}

void SimpleMergerWindow::ColumnsEditChanged(const QString & editText, int id) {
    QStringList l = editText.split(",", QString::SkipEmptyParts);
    emit signal_SetFileColumns(l, id);
}

void SimpleMergerWindow::ActivateMergeButton() {
    if(fileOneOpened && fileTwoOpened && outFileOpened)
        ui->mergeButton->setEnabled(true);
    else
        ui->mergeButton->setEnabled(false);
}

