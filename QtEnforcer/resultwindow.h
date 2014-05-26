#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QDialog>
class QStringList;

namespace Ui {
    class ResultWindow;
}

class ResultWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResultWindow(QWidget *parent = 0);
    ~ResultWindow();
    void setResultsToPrint(const QStringList* results);

signals:
    void signal_SaveFile();
private slots:
    void saveFile();

private:
    Ui::ResultWindow *ui;

};

#endif // RESULTWINDOW_H
