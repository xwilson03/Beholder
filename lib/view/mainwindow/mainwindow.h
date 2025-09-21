#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include "combatpanel.h"
#include "featurepanel.h"
#include "inventorypanel.h"
#include "nameplate.h"
#include "spellpanel.h"
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
        SpellPanel* aSpellPanel,
        QWidget* parent = nullptr
    );

private:
    NamePlate*   mNamePlate;
    StatPanel*   mStatPanel;
    CombatPanel* mCombatPanel;
    FeaturePanel* mFeaturePanel;
    InventoryPanel* mInventoryPanel;
    SpellPanel* mSpellPanel;
};

#endif // MAINWINDOW_H
