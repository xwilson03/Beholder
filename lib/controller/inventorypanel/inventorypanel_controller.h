#ifndef INVENTORYPANEL_CONTROLLER_H
#define INVENTORYPANEL_CONTROLLER_H


#include <QObject>

#include "inventorypanel.h"
#include "store.h"


class InventoryPanelController : QObject {

    Q_OBJECT

public:
    InventoryPanelController(
        InventoryPanel* aView,
        Store&     aStore,
        QObject*   parent = nullptr
    );

private:
    InventoryPanel* mView;
    Store&     mStore;

};


#endif // INVENTORYPANEL_CONTROLLER_H
