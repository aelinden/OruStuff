#include "resultwindow.h"
#include "ui_resultwindow.h"
#include <QDebug> // Temporary
#include <QStringList> // Temp

ResultWindow::ResultWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveFile()));
}

ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::setResultsToPrint(const QStringList *results)
{
    qDebug() << "In result window. Will set results to print" << endl;

    QStringList::const_iterator it;
    for(it = results->begin(); it != results->end(); ++it)
        qDebug() << (*it) << endl;

}

void ResultWindow::saveFile()
{

}

