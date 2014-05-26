#include "resultwindow.h"
#include "ui_resultwindow.h"
#include <QDebug> // Temporary
#include <QStringList> // Temp
#include <QTableWidget>
#include <QTableWidgetItem>

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

    int nr_rows = results->size();
    ui->tableWidget->setRowCount(nr_rows);

    QStringList::const_iterator it;
    int current_column = 0;
    int current_row = 0;
    for(it = results->begin(); it != results->end(); ++it)
    {
        QStringList current_row_split = (*it).split('\t');
        foreach(QString str, current_row_split)
        {
            qDebug() << "I setResultsToPrint: " << str;
            ui->tableWidget->setColumnCount(current_row_split.size());
            QTableWidgetItem *item = new QTableWidgetItem(str);
            item->setText(str);
            ui->tableWidget->setItem(current_row, current_column, item);
            ++current_column;
        }
        current_column = 0;
        current_row++;
    }
}

void ResultWindow::saveFile()
{
    emit signal_SaveFile();
}

