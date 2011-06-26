#ifndef PRESENTER_H
#define PRESENTER_H

#include <QObject>
#include <QList>

class ResultWindow;
class EnforcerWindow;
class FileProcessor;
class EnforcerProcessBehaviour;

class Presenter : public QObject
{
    Q_OBJECT

public:
    explicit Presenter(QObject *parent);
    ~Presenter();

private:
    void connectSlotsAndSignals();
    EnforcerWindow *mainWindow;
    ResultWindow *resultWindow;
    FileProcessor *processor;
    EnforcerProcessBehaviour *behaviour;
};

#endif // PRESENTER_H
