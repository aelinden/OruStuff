#ifndef PRESENTER_H
#define PRESENTER_H

#include <QObject>
#include <QList>

class SimpleMergerWindow;
class FileProcessor;
class SimpleProcessBehaviour;

class Presenter : public QObject
{
    Q_OBJECT

public:
    explicit Presenter(QObject *parent);
    ~Presenter();

private:
    void connectSlotsAndSignals();
    SimpleMergerWindow *mainWindow;
    FileProcessor *processor;
    SimpleProcessBehaviour *behaviour;
};

#endif // PRESENTER_H
