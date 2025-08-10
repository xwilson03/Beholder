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


    NamePlate* namePlate = new NamePlate();

    StatPanel* statPanel = new StatPanel();

    CombatPanel* combatPanel = new CombatPanel();

    MainWindow window (
        namePlate,
        statPanel,
        combatPanel
    );


    NamePlateController namePlateController (
        namePlate,
        store
    );

    StatPanelController statPanelController (
        statPanel,
        store
    );


    window.show();
    return app.exec();
}
