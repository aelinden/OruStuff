#ifndef PROCESSBEHAVIOUR_H
#define PROCESSBEHAVIOUR_H

#include <QList>
#include <QObject>
class FileProcessor;

/*
 * The process behaviour base class. A pure virtual
 */
class ProcessBehaviour : public QObject {
    Q_OBJECT
public:
    ProcessBehaviour(QObject *parent = 0);
    virtual ~ProcessBehaviour();
    virtual void Process(FileProcessor*) = 0;
};

/*
 * Process behaviour used by the SimpleMerger.
 * -- Members functions --
 * - Process(FileProcessor*)
 *      Starts the process with data supplied by the file processor
 */
class SimpleProcessBehaviour : public ProcessBehaviour {
    Q_OBJECT
public:
    SimpleProcessBehaviour(QObject *parent = 0);
    virtual ~SimpleProcessBehaviour();
    virtual void Process(FileProcessor*);
public slots:
    void slot_SetFileColumns(const QStringList &, int);
signals:
    void signal_FileColumnsSet();
private:
    QList<int> m_fileOneColumns; // Columns to pick from file one
    QList<int> m_fileTwoColumns; // Columns to pick from file two
};

/*
 * Process behaviour used by the QtEnforcer.
 * -- Member functions --
 * - Process(FileProcessor*)
 *      Starts the process with data supplied by the file processor
 */
class EnforcerProcessBehaviour : public ProcessBehaviour {
    Q_OBJECT
public:
    EnforcerProcessBehaviour(QObject *parent = 0);
    virtual ~EnforcerProcessBehaviour();
    virtual void Process(FileProcessor*);
public slots:
        void slot_SetRequiredMatches(int);
signals:
        void signal_RequiredMatchesSet();
private:
        QList<int> m_comparedColumns; // List of columns to compare
        int m_requiredMatches; // Matches required to be considered a hit
        int m_currentMatches;     // Counter to keep track of matches during a comparison
};

#endif // PROCESSBEHAVIOUR_H
