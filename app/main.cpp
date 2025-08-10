#include <QApplication>

#include "mainwindow.h"

#include "combatpanel.h"
#include "nameplate.h"
#include "nameplate_controller.h"
#include "statpanel.h"
#include "statpanel_controller.h"
#include "store.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Store store;

    std::string name;
    int         level;
    std::string characterClass;
    std::string race;

    {
        Store::Accessor state = store.getState();
        name = state->name;
        level = state->level;
        characterClass = state->characterClass;
        race = state->race;
    }

    NamePlate* namePlate = new NamePlate();

    StatBox* strengthBox     = new StatBox("STR");
    StatBox* dexterityBox    = new StatBox("DEX");
    StatBox* constitutionBox = new StatBox("CON");
    StatBox* intelligenceBox = new StatBox("INT");
    StatBox* wisdomBox       = new StatBox("WIS");
    StatBox* charismaBox     = new StatBox("CHA");

    StatPanel* statPanel = new StatPanel(
        strengthBox,
        dexterityBox,
        constitutionBox,
        intelligenceBox,
        wisdomBox,
        charismaBox
    );

    CombatPanel* combatPanel = new CombatPanel();

    NamePlateController namePlateController (
        namePlate,
        store
    );

    StatPanelController statPanelController (
        strengthBox,
        dexterityBox,
        constitutionBox,
        intelligenceBox,
        wisdomBox,
        charismaBox,
        store
    );

    MainWindow window (
        namePlate,
        statPanel,
        combatPanel
    );
    window.show();

    return app.exec();
}
