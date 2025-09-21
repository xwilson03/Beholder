#ifndef SPELLPANEL_CONTROLLER_H
#define SPELLPANEL_CONTROLLER_H


#include <QObject>

#include "spellpanel.h"
#include "store.h"


class SpellPanelController : QObject {

    Q_OBJECT

public:
    SpellPanelController(
        SpellPanel* aView,
        Store&     aStore,
        QObject*   parent = nullptr
    );

private:
    SpellPanel* mView;
    Store&     mStore;

};


#endif // SPELLPANEL_CONTROLLER_H
