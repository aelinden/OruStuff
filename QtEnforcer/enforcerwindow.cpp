#include "enforcerwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStringList>
#include <QRegExp>
#include <QDebug> // Temporary
#include "../FileProcessor/FileProcessor/fileprocessor.h"

EnforcerWindow::EnforcerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     * Connects button clicks to proper actions
     */
    QObject::connect(ui->selTargetBtn, SIGNAL(clicked()), this, SLOT(slot_onTargetFileClick()));
    QObject::connect(ui->selSnowballBtn, SIGNAL(clicked()), this, SLOT(slot_onSnowballFileClick()));
    QObject::connect(ui->saveFileButton, SIGNAL(clicked()), this, SLOT(slot_onSaveFileClick()));
    QObject::connect(ui->actionButton, SIGNAL(clicked()), this, SLOT(slot_onStartScan()));


    /*
     * Connects line edit changes to functions that will pass along the entered text to the presenter
     */
    QObject::connect(ui->comparedColumnsEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_onComparedColumnsChanged()));
    QObject::connect(ui->requiredMatchesEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_onRequiredMatchingColumnsChanged()));

    /*
     * Makes sure all required items are set before enabling the action button
     */
    QObject::connect(ui->comparedColumnsEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_enableScanButton()));
    QObject::connect(ui->requiredMatchesEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_enableScanButton()));
    QObject::connect(ui->selTargetBtn, SIGNAL(clicked()), this, SLOT(slot_enableScanButton()));
    QObject::connect(ui->selSnowballBtn, SIGNAL(clicked()), this, SLOT(slot_enableScanButton()));


    QObject::connect(this, SIGNAL(signal_EnableViewButton()), this, SLOT(slot_enableViewButton()));
    QObject::connect(ui->viewButton, SIGNAL(clicked()), this, SLOT(slot_onViewClick()));

    // Enabled when user enters correct text in text edits
    comparedColumnsSet = false;
    requiredMatchingColumnsSet = false;

    // Enabled when files has been chosen
    //targetFilePicked = false;
    //snowballFilePicked = false;
    fileOnePicked = false;
    fileTwoPicked = false;
    outFilePicked = false;

    /*
     * Validators used to make sure user input is correct in line edits
     */
    QRegExp matchingColsRegExp("\\d+(,\\d+)*"); // Match a number followed by 0 or more comma followed by a number
    QRegExp numMatchingColsRegExp("\\d+");      // Match a number

    comparedColumnsValidator = new QRegExpValidator(matchingColsRegExp, this);
    requiredMatchingColumnsValidator = new QRegExpValidator(numMatchingColsRegExp, this);

    ui->comparedColumnsEdit->setValidator(comparedColumnsValidator);
    ui->requiredMatchesEdit->setValidator(requiredMatchingColumnsValidator);

    // DEBUG
    ui->viewButton->setEnabled(true);
}


EnforcerWindow::~EnforcerWindow()
{
    delete ui;
    delete comparedColumnsValidator;
    delete requiredMatchingColumnsValidator;
}

void EnforcerWindow::slot_FileOpened(FileProcessor::FileId fileId, const QString &fileName) {
    switch(fileId) {
    case FileProcessor::FILE_ONE:
        ui->fileOneLabel->setText(fileName);
        fileOnePicked = true;
        break;
    case FileProcessor::FILE_TWO:
        ui->fileTwoLabel->setText(fileName);
        fileTwoPicked = true;
        break;
    case FileProcessor::OUT_FILE:
        ui->outFileLabel->setText(fileName);
        outFilePicked = true;
        break;
    default:
        qDebug() << "You're not supposed to be here." << endl
                    << "Error in file opening, id: " << fileId << ", file name: " << fileName << endl;
        break;
    }
    slot_enableScanButton();
}

/*
 * Helper functions for opening files. Two for the two in files, one for the out file.
 */
void EnforcerWindow::slot_onTargetFileClick() {
    OpenFile(FileProcessor::FILE_ONE, QFileDialog::AcceptOpen);
}

void EnforcerWindow::slot_onSnowballFileClick() {
    OpenFile(FileProcessor::FILE_TWO, QFileDialog::AcceptOpen);
}

void EnforcerWindow::slot_onSaveFileClick() {
    OpenFile(FileProcessor::OUT_FILE, QFileDialog::AcceptSave);
}

/*
 * Shows a file dialog with accept mode acceptMode (Open or save).
 */
void EnforcerWindow::OpenFile(FileProcessor::FileId fileId, QFileDialog::AcceptMode acceptMode) {
    QFileDialog *picker = new QFileDialog(this, Qt::Window);
    picker->setAcceptMode(acceptMode);
    QStringList picked;
    int dialogCode = picker->exec();

    if(dialogCode == QFileDialog::Accepted) {
        picked = picker->selectedFiles();
        emit signal_OpenFile(fileId, picked[0]); // picked[0] since we want the first picked file.
    }
    else {
        qDebug() << "User cancelled file selection" << endl;
    }
    delete picker;
}

/*
 * Start button is clicked, start the scan
 */
void EnforcerWindow::slot_onStartScan()
{
    ui->actionButton->setText(tr("Scanning..."));
    ui->actionButton->setEnabled(false);
    emit signal_StartScan();
}

/*
 * Comparison columns has been set in file processor
 */
void EnforcerWindow::slot_onComparedColumnsSet()
{
    comparedColumnsSet = true;
    slot_enableScanButton();
}

/*
 * Number of matching columns has been set in file processor
 */
void EnforcerWindow::slot_onRequiredMatchingColumnsSet()
{
    requiredMatchingColumnsSet = true;
    slot_enableScanButton();
}

/*
 * The text on matching columns text entry has been modified.
 * If it's not empty, send the text to the presenter.
 */
void EnforcerWindow::slot_onComparedColumnsChanged()
{
    if(ui->comparedColumnsEdit->text().isEmpty())
    {
        comparedColumnsSet = false;
    }
    else
    {
        QList<int> compareColumns;
        QString s = ui->comparedColumnsEdit->text();

        QStringList l = s.split(",", QString::SkipEmptyParts);
        QStringList::const_iterator it;
        for(it = l.begin(); it != l.end(); ++it)
        {
            compareColumns.append((*it).toInt());
        }

        emit signal_SetComparedColumns(compareColumns);
    }
}

/*
 * Same as onMatchingColumnsChanged() above only with number of matching columns entry
 */
void EnforcerWindow::slot_onRequiredMatchingColumnsChanged()
{
    if(ui->requiredMatchesEdit->text().isEmpty())
    {
        requiredMatchingColumnsSet = false;
    }
    else
    {
        int i = ui->requiredMatchesEdit->text().toInt();
        emit signal_SetRequiredMatchingColumns(i);
    }
}

/*
 * Comparison is done. Present results
 */
void EnforcerWindow::slot_onProcessingDone()
{
    ui->actionButton->setText(tr("Scan"));
    ui->actionButton->setEnabled(true);

    // Enable view button
    fileScanned = true;
    emit signal_EnableViewButton();
}

/*
 * Enables the action button if all required items have been set
 */
void EnforcerWindow::slot_enableScanButton()
{
    if(comparedColumnsSet && requiredMatchingColumnsSet && fileOnePicked && fileTwoPicked && outFilePicked) //targetFilePicked && snowballFilePicked)
        ui->actionButton->setEnabled(true);
    else
        ui->actionButton->setEnabled(false);
}

/*
 * Enables the view button if file has been scanned
 */
void EnforcerWindow::slot_enableViewButton()
{
    if(fileScanned)
        ui->viewButton->setEnabled(true);
    else
        ui->viewButton->setEnabled(false);
}

// View button has been clicked.
void EnforcerWindow::slot_onViewClick()
{
    qDebug() << "In main window, will send result signal" << endl;
    emit signal_ViewResults();
    qDebug() << "in main window, result signal sent" << endl;
}

