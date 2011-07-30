#include "processbehaviour.h"
#include "fileprocessor.h"
#include <QStringList>
#include <QTextStream>
#include <QDebug>

ProcessBehaviour::ProcessBehaviour(QObject *parent) : QObject(parent) {
    // Nothing
}

ProcessBehaviour::~ProcessBehaviour() {
    // Nothing
}

SimpleProcessBehaviour::SimpleProcessBehaviour(QObject *parent) : ProcessBehaviour(parent) {
    // Nothing
}

SimpleProcessBehaviour::~SimpleProcessBehaviour() {
    // Nothing
}

/*
 * Set the columns from file with id fileId to pick when match column matches.
 */
void SimpleProcessBehaviour::slot_SetFileColumns(const QStringList & columns, int fileId) {
    QList<int> *temporaryColumnsList = NULL;
    QStringList::const_iterator it;

    switch(fileId)
    {
    case FileProcessor::FILE_ONE:
        temporaryColumnsList = &m_fileOneColumns;
        qDebug() << "File one columns changed" << endl;
        break;
    case FileProcessor::FILE_TWO:
        temporaryColumnsList = &m_fileTwoColumns;
        qDebug() << "File two columns changed" << endl;
        break;
    }

    temporaryColumnsList->clear();
    for(it = columns.begin(); it != columns.end(); ++it)
    {
        temporaryColumnsList->append((*it).toInt());
        qDebug() << (*it) << " added to column list" << endl;
    }
}

/*
 * Go through each line from both files and split them up using a delimiter.
 * If the match columns matches, create a new string with contents from chosen columns from each file.
 * Write the results to an output stream.
 */
void SimpleProcessBehaviour::Process(FileProcessor *processor) {
    processor->ReadFromFile(FileProcessor::FILE_ONE);
    processor->ReadFromFile(FileProcessor::FILE_TWO);

    QStringList::const_iterator it;
    QStringList::const_iterator it2;

    /*
     * Create string and connect a text stream to it
     */
    QString outString;
    QTextStream outStringStream(&outString);

    /*
     * Contains contents of the current row from each file, split using delimiter
     */
    QStringList fileOneLineSplit;
    QStringList fileTwoLineSplit;

    /*
     * Splits each file from both files. Delimiter is currently hardcoded to tab. Should be selectable in main window
     */
    for(it = processor->m_fileOneContents->begin(); it != processor->m_fileOneContents->end(); ++it) {
        fileOneLineSplit = (*it).split('\t', QString::KeepEmptyParts);
        for(it2 = processor->m_fileTwoContents->begin(); it2 != processor->m_fileTwoContents->end(); ++it2) {
            fileTwoLineSplit = (*it2).split('\t', QString::KeepEmptyParts);

            /*
             * If contents of "cell" at index process->m_matchColumn[0] match from both files, it's a hit and should be merged.
             */
            if(fileOneLineSplit[processor->m_matchColumns[0]] == (fileTwoLineSplit[processor->m_matchColumns[0]])) {
                foreach(int i, m_fileOneColumns) {
                    if(fileOneLineSplit.size() > i)
                        outStringStream << fileOneLineSplit[i] << '\t';
                }
                foreach(int j, m_fileTwoColumns) {
                    if(fileTwoLineSplit.size() > j)
                        outStringStream << fileTwoLineSplit[j] << '\t';
                }

                /*
                 * Add a new line to the end of the string and append it to the results list in processor.
                 */
                outStringStream << endl;
                processor->m_results->append(outString);
                outString.clear();
                break;
            }
        }
    }
    // For the time being save the results directly (UI has no save button).
    // Should emit signal that file has been saved so a popup can be shown with a message.
    processor->SaveResultsToFile();
}

EnforcerProcessBehaviour::EnforcerProcessBehaviour(QObject *parent) : ProcessBehaviour(parent) {
    // Nothing
}

EnforcerProcessBehaviour::~EnforcerProcessBehaviour() {
    //Nothing
}

void EnforcerProcessBehaviour::slot_SetRequiredMatches(int i) {
    qDebug() << "Will set required matches to " << i << endl;
    m_requiredMatches = i;
    emit signal_RequiredMatchesSet();
}


void EnforcerProcessBehaviour::Process(FileProcessor *processor) {
    // Add process behaviour for EnforcerProcessBehaviour
    processor->ReadFromFile(FileProcessor::FILE_ONE);
    processor->ReadFromFile(FileProcessor::FILE_TWO);


}


