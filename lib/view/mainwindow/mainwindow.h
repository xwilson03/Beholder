#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include "combatpanel.h"
#include "nameplate.h"
#include "statpanel.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(
        NamePlate*   aNamePlate,
        StatPanel*   aStatPanel,
        CombatPanel* aCombatPanel,
        QWidget* parent = nullptr
    );

private:
    NamePlate*   mNamePlate;
    StatPanel*   mStatPanel;
    CombatPanel* mCombatPanel;
};

#endif // MAINWINDOW_H
