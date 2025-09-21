#include <QApplication>

#include "mainwindow.h"

#include "combatpanel.h"
#include "combatpanel_controller.h"
#include "nameplate.h"
#include "nameplate_controller.h"
#include "statpanel.h"
#include "statpanel_controller.h"
#include "featurepanel.h"
#include "featurepanel_controller.h"
#include "inventorypanel.h"
#include "inventorypanel_controller.h"
#include "spellpanel.h"
#include "spellpanel_controller.h"
#include "store.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    Store store;


    NamePlate* namePlate = new NamePlate();
    StatPanel* statPanel = new StatPanel();
    CombatPanel* combatPanel = new CombatPanel();
    FeaturePanel* featurePanel = new FeaturePanel();
    InventoryPanel* inventoryPanel = new InventoryPanel();
    SpellPanel* spellPanel = new SpellPanel();

    MainWindow window (
        namePlate,
        statPanel,
        combatPanel,
        featurePanel,
        inventoryPanel,
        spellPanel
    );


    NamePlateController namePlateController (
        namePlate,
        store
    );

    StatPanelController statPanelController (
        statPanel,
        store
    );

    CombatPanelController combatPanelController (
        combatPanel,
        store
    );

    FeaturePanelController featurePanelController (
        featurePanel,
        store
    );

    InventoryPanelController inventoryPanelController (
        inventoryPanel,
        store
    );

    SpellPanelController SpellPanelController (
        spellPanel,
        store
    );

    window.show();
    return app.exec();
}
