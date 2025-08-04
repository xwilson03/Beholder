#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

#include "store.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(
        Store& aStore,
        QWidget *parent = nullptr
    );

private:
    Store& mStore;
};

#endif // MAINWINDOW_H
