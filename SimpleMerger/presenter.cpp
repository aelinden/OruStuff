#include "presenter.h"
#include "simplemergerwindow.h"
#include "../FileProcessor/FileProcessor/fileprocessor.h"
#include "../FileProcessor/FileProcessor/processbehaviour.h"
#include <QObject>
#include <QDebug>

/*
 * The presenter deals with signals and slots between the comparer (Model) and the main window (View).
 * Using this design pattern, the internals and the UI does not need to know about eachother.
 */

Presenter::Presenter(QObject *parent) : QObject(parent)
{
    mainWindow = new SimpleMergerWindow();
    behaviour = new SimpleProcessBehaviour();
    processor = new FileProcessor(behaviour);
    connectSlotsAndSignals();
    mainWindow->show();
}

Presenter::~Presenter()
{

}

void Presenter::connectSlotsAndSignals() {
    qDebug() << "Connect stuff" << endl;
}
