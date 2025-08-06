#include <QApplication>

#include "mainwindow.h"

#include "combatpanel.h"
#include "nameplate.h"
#include "statpanel.h"
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

    NamePlate* namePlate = new NamePlate(
        name,
        level,
        characterClass,
        race
    );
    StatPanel* statPanel = new StatPanel();
    CombatPanel* combatPanel = new CombatPanel();

    MainWindow window (
        namePlate,
        statPanel,
        combatPanel
    );
    window.show();

    return app.exec();
}
