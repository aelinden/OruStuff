#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <QObject>
#include <QList>
#include "processbehaviour.h"
class QStringList;
class QString;
class QFile;

/*
 * Type of process behaviour to use. Maybe pass in constructor instead of ProcessBehaviour?
 */
namespace Processor {
    enum ProcessType { MERGER, ENFORCER, PNP };
}

/*
 * The file processor is used by all programs. It contains a process behaviour pointer
 * that depending on the caller is set to the correct behaviour.
 *
 * -- Member functions --
 * - SetProcessBehaviour(ProcessBehaviour*) [Public]
 *      Sets the process behaviour of the file processor to the supplied behaviour
 * - ReadFromFile(int) [Protected]
 *      Reads data from the file with the supplied id
 *
 * -- Public slots --
 * - slot_OpenFile(int, const QString &)
 *      Opens the file with the supplied file name. Depening on file id, an in- or out file.
 * - slot_Process()
 *      Starts the file processing with the active process behaviour
 * - slot_SetComparedColumns(int)
 *      Sets which column(s) should be used to match the two files being processed.
 * - slot_SetComparedColumns(const QList<int> &)
 *      Overloaded function
 * - slot_SetFileColumns(QStringList, int)
 *      Sets the columns to merge into the new results from file with supplied id
 * - slot_SetRequiredMatches(int)
 *      Sets the required matches variable used by the Enforcer.
 *
 * -- Signals --
 * - signal_FileOpened(int, QString)
 *      Emits when the file with the supplied id has been opened.
 * - signal_MatchColumnsSet()
 *      Emits when match columns has been set.
 * - signal_FileColumnsSet(int)
 *      Emits when columns for the file with the supplied id has been set.
 * - signal_ProcessingDone()
 *      Emits when processing is completed
 *
 * -- Other --
 * - Copy constructor and assignment operator is private to prevent copying and assignment.
 * - SimpleProcessBehaviour and EnforceProcessBehaviour classes are friends so they can access private members.
 */
class FileProcessor : public QObject
{
    Q_OBJECT
public:
    enum FileId { FILE_ONE, FILE_TWO, OUT_FILE };
    FileProcessor(ProcessBehaviour *behaviour = 0, QObject *parent = 0);
    virtual ~FileProcessor();
    void SetProcessBehaviour(ProcessBehaviour *behaviour);
    const QStringList* GetResults() const;
    void SaveResultsToFile();
    friend class SimpleProcessBehaviour;
    friend class EnforcerProcessBehaviour;
public slots:
    void slot_OpenFile(FileProcessor::FileId, const QString &);
    void slot_Process();
    void slot_SetComparedColumns(int);
    void slot_SetComparedColumns(const QList<int> &);
signals:
    void signal_FileOpened(FileProcessor::FileId, const QString &);
    void signal_ComparedColumnsSet();
    void signal_ProcessingDone();
protected:
    void ReadFromFile(FileId id);
private:
    FileProcessor(const FileProcessor &); // File processor should not be copied
    FileProcessor & operator=(const FileProcessor &); // Or assigned
    ProcessBehaviour *m_pb;
    QStringList *m_fileOneContents;
    QStringList *m_fileTwoContents;
    QFile *m_fileOne;
    QFile *m_fileTwo;
    QFile *m_outFile;

    QList<int> m_matchColumns; // Column(s) to match files with

    QStringList *m_results; // List to append results to
};

#endif // FILEPROCESSOR_H
