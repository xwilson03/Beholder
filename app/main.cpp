#include <QApplication>

#include "mainwindow.h"
#include "store.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Store store;
    // set initial state

    MainWindow w (store);
    w.show();

    return a.exec();
}
