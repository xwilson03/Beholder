#ifndef NAMEPLATE_CONTROLLER_H
#define NAMEPLATE_CONTROLLER_H


#include <QObject>

#include "nameplate.h"
#include "store.h"


class NamePlateController : public QObject {

    Q_OBJECT

public:
    NamePlateController(
        NamePlate* aView,
        Store&     aStore,
        QObject*   parent = nullptr
    );

    void onStateChanged();

private:
    NamePlate* mView;
    Store&     mStore;

};


#endif // NAMEPLATE_CONTROLLER_H
