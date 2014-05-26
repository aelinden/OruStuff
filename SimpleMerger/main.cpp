#include <QApplication>
#include "simplemergerwindow.h"
#include "../FileProcessor/FileProcessor/fileprocessor.h"
#include "presenter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //SimpleMergerWindow w;
    //SimplePresenter presenter(&w, &w);
    //w.show();
    //presenter.displayMain();

    Presenter presenter(&a);

    return a.exec();
}
