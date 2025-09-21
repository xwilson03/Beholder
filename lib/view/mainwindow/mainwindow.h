#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include "combatpanel.h"
#include "featurepanel.h"
#include "inventorypanel.h"
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
        FeaturePanel* aFeaturePanel,
        InventoryPanel* aInventoryPanel,
        QWidget* parent = nullptr
    );

private:
    NamePlate*   mNamePlate;
    StatPanel*   mStatPanel;
    CombatPanel* mCombatPanel;
    FeaturePanel* mFeaturePanel;
    InventoryPanel* mInventoryPanel;
};

#endif // MAINWINDOW_H
