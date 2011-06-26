#include <QtGui/QApplication>
#include "presenter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Presenter presenter(&a);

    return a.exec();
}
