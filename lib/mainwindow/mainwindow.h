#pragma once

#include <QMainWindow>
#include <QObject>
#include <QWidget>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(
        QWidget* parent = nullptr
    );

private:
};
