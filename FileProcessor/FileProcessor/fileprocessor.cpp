#include "fileprocessor.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>

/*
 * File Processor section
 */
FileProcessor::FileProcessor(ProcessBehaviour *behaviour, QObject *parent) :
    QObject(parent)
{
    m_pb = behaviour;
    m_fileOne = new QFile();
    m_fileTwo = new QFile();
    m_outFile = new QFile();
    m_results = new QStringList();
    m_fileOneContents = new QStringList();
    m_fileTwoContents = new QStringList();
}

FileProcessor::~FileProcessor() {
    delete m_pb;
    delete m_results;
    delete m_fileOneContents;
    delete m_fileTwoContents;
    m_fileOne->close();
    delete m_fileOne;
    m_fileTwo->close();
    delete m_fileTwo;
    m_outFile->close();
    delete m_outFile;
}

void FileProcessor::SetProcessBehaviour(ProcessBehaviour *behaviour) {
    m_pb = behaviour;
}

const QStringList* FileProcessor::GetResults() const {
    return m_results;
}

void FileProcessor::SaveResultsToFile() {
    QTextStream outStream((QIODevice*)m_outFile);
    foreach(QString s, *m_results) {
        outStream << s;
    }
}

void FileProcessor::ReadFromFile(FileId fileId) {
    QStringList *list = NULL;
    QTextStream *stream = NULL;
    QString temp;
    switch(fileId) {
    case FILE_ONE:
        stream = new QTextStream(m_fileOne);
        list = m_fileOneContents;
        break;
    case FILE_TWO:
        stream = new QTextStream(m_fileTwo);
        list = m_fileTwoContents;
        break;
    }

    while(!stream->atEnd()) {
        list->append(stream->readLine());
    }

    delete stream;
}

void FileProcessor::slot_OpenFile(FileProcessor::FileId fileId, const QString & fileName) {
    qDebug() << "Will open file " << fileName << " with fileId " << fileId << endl;
    QFile *file = NULL;
    switch(fileId) {
    case FileProcessor::FILE_ONE :
        file = m_fileOne;
        if(m_fileOne->isOpen()) {
            m_fileOne->close();
            m_fileOneContents->clear();
        }
        m_fileOne->setFileName(fileName);
        m_fileOne->open(QIODevice::ReadOnly);
        emit signal_FileOpened(fileId, fileName);
        break;
    case FileProcessor::FILE_TWO :
        file = m_fileTwo;
        if(m_fileTwo->isOpen()) {
            m_fileTwo->close();
            m_fileTwoContents->clear();
        }
        m_fileTwo->setFileName(fileName);
        m_fileTwo->open(QIODevice::ReadOnly);
        emit signal_FileOpened(fileId, fileName);
        break;
    case FileProcessor::OUT_FILE :
        file = m_outFile;
        if(m_outFile->isOpen()) {
            m_outFile->close();
        }
        m_outFile->setFileName(fileName);
        m_outFile->open(QIODevice::WriteOnly);
        emit signal_FileOpened(fileId, fileName);
        break;
    default:
        qDebug() << "fileId error! You should not be here!" << endl;
        break;
    }
}

void FileProcessor::slot_Process() {
    m_results->clear();
    if(m_pb != 0)
        m_pb->Process(this);
    emit signal_ProcessingDone();
}

/*
 * Overloaded function, receives an int from simple merger, or a list of
 * integers from enforcer. Signals when variable has been set
 */
void FileProcessor::slot_SetComparedColumns(int i) {
    qDebug() << "Will set compared columns to " << i << endl;
    m_matchColumns.clear();
    m_matchColumns.append(i);
    emit signal_ComparedColumnsSet();
}

void FileProcessor::slot_SetComparedColumns(const QList<int> & columns) {
    qDebug() << "Will set compared columns to ";
    foreach(int j, columns)
        qDebug() << j;
    m_matchColumns.clear();
    foreach(int i, columns) {
        m_matchColumns.append(i);
    }
    emit signal_ComparedColumnsSet();
}
