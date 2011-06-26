#ifndef ENFORCERWINDOW_H
#define ENFORCERWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QFileDialog>
#include "../../FileProcessor/FileProcessor/fileprocessor.h"
class QRegExpValidator;
class QStringList;

namespace Ui {
    class MainWindow;
}

/*
 * TODO:
 *  - Enable use of radio buttons
 */
class EnforcerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EnforcerWindow(QWidget *parent = 0);
    ~EnforcerWindow();
    void OpenFile(FileProcessor::FileId, QFileDialog::AcceptMode);

public slots:
    void slot_FileOpened(FileProcessor::FileId fileId, const QString & fileName);
    void slot_onComparedColumnsSet();
    void slot_onRequiredMatchingColumnsSet();
    void slot_onProcessingDone();

signals:
    void signal_OpenFile(FileProcessor::FileId, const QString &);
    void signal_SetSaveFile(const QString);
    void signal_StartScan();
    void signal_SetComparedColumns(const QList<int> & cols);
    void signal_SetRequiredMatchingColumns(int i);
    void signal_ViewResults();
    void signal_EnableViewButton();

private slots:
    void slot_onTargetFileClick();
    void slot_onSnowballFileClick();
    void slot_onSaveFileClick();
    void slot_onComparedColumnsChanged();
    void slot_onRequiredMatchingColumnsChanged();
    void slot_onStartScan();
    void slot_enableScanButton();
    void slot_enableViewButton();
    void slot_onViewClick();

private:
    Ui::MainWindow *ui;
    QRegExpValidator *comparedColumnsValidator;
    QRegExpValidator *requiredMatchingColumnsValidator;
    bool comparedColumnsSet;
    bool requiredMatchingColumnsSet;
    bool fileOnePicked;
    bool fileTwoPicked;
    bool outFilePicked;
    bool fileScanned;
};

#endif // ENFORCERWINDOW_H
