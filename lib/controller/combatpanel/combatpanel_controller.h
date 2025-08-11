#ifndef COMBATPANEL_CONTROLLER_H
#define COMBATPANEL_CONTROLLER_H


#include <QObject>

#include "combatpanel.h"
#include "store.h"


class CombatPanelController : QObject {

    Q_OBJECT

public:
    CombatPanelController(
        CombatPanel* aView,
        Store&     aStore,
        QObject*   parent = nullptr
    );

private:
    CombatPanel* mView;
    Store&     mStore;

};


#endif // COMBATPANEL_CONTROLLER_H
