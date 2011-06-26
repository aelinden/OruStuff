#ifndef SIMPLEMERGERWINDOW_H
#define SIMPLEMERGERWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QList>

namespace Ui {
    class SimpleMergerWindow;
}

class SimpleMergerWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum COLUMNSID { FILE_ONE, FILE_TWO, MATCH };
    explicit SimpleMergerWindow(QWidget *parent = 0);
    ~SimpleMergerWindow();
    void OpenFile(int, QFileDialog::AcceptMode);
    void ColumnsEditChanged(const QString &, int);
    void ReadFile(int);
signals:
    void signal_StartProcess();
    void signal_OpenFile(int, const QString &);
    void signal_SetMatchColumn(int);
    void signal_SetFileColumns(QStringList, int);
public slots:
    void slot_Merge();
    void slot_OpenFileOne();
    void slot_OpenFileTwo();
    void slot_FileOpened(int, const QString &);
    void slot_SelectSaveFile();
    void slot_FileOneColumnsEditChanged(const QString &);
    void slot_FileTwoColumnsEditChanged(const QString &);
    void slot_MatchColumnEditChanged(const QString &);
private:
    void ActivateMergeButton();
    Ui::SimpleMergerWindow *ui;
    bool fileOneOpened;
    bool fileTwoOpened;
    bool outFileOpened;
};

#endif // SIMPLEMERGERWINDOW_H
