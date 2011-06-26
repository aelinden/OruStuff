#include "presenter.h"
#include "resultwindow.h"
#include "enforcerwindow.h"
#include "../../FileProcessor/FileProcessor/fileprocessor.h"
#include "../../FileProcessor/FileProcessor/processbehaviour.h"
#include <QObject>
#include <QDebug>

/*
 * The presenter deals with signals and slots between the comparer (Model) and the main window (View).
 * Using this design pattern, the internals and the UI does not need to know about eachother.
 */

Presenter::Presenter(QObject *parent) : QObject(parent)
{
    mainWindow = new EnforcerWindow();
    behaviour = new EnforcerProcessBehaviour();
    processor = new FileProcessor(behaviour);
    connectSlotsAndSignals();
    mainWindow->show();
}

Presenter::~Presenter()
{

}

void Presenter::connectSlotsAndSignals() {
    // Signals from GUI to file processor
    QObject::connect(mainWindow, SIGNAL(signal_OpenFile(FileProcessor::FileId,const QString &)), processor, SLOT(slot_OpenFile(FileProcessor::FileId, const QString &)));
    QObject::connect(mainWindow, SIGNAL(signal_SetComparedColumns(QList<int>)), processor, SLOT(slot_SetComparedColumns(QList<int>)));
    QObject::connect(mainWindow, SIGNAL(signal_StartScan()), processor, SLOT(slot_Process()));
    // Signals from GUI to behaviour
    QObject::connect(mainWindow, SIGNAL(signal_SetRequiredMatchingColumns(int)), behaviour, SLOT(slot_SetRequiredMatches(int)));
    // Signals from processor to GUI
    QObject::connect(processor, SIGNAL(signal_FileOpened(FileProcessor::FileId,QString)), mainWindow, SLOT(slot_FileOpened(FileProcessor::FileId,QString)));
    QObject::connect(processor, SIGNAL(signal_ProcessingDone()), mainWindow, SLOT(slot_onProcessingDone()));
    QObject::connect(processor, SIGNAL(signal_ComparedColumnsSet()), mainWindow, SLOT(slot_onComparedColumnsSet()));
    // Signals from behaviour to GUI
    QObject::connect(behaviour, SIGNAL(signal_RequiredMatchesSet()), mainWindow, SLOT(slot_onRequiredMatchingColumnsSet()));
}
