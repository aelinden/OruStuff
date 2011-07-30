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

/*
 * Connect slots and signals between UI and file processor/process behaviour
 */
void Presenter::connectSlotsAndSignals() {
    QObject::connect(mainWindow, SIGNAL(signal_OpenFile(FileProcessor::FileId ,QString)), processor, SLOT(slot_OpenFile(FileProcessor::FileId,QString)));
    QObject::connect(processor, SIGNAL(signal_FileOpened(FileProcessor::FileId,QString)), mainWindow, SLOT(slot_FileOpened(FileProcessor::FileId ,QString)));
}
