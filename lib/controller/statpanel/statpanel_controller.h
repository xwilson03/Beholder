#ifndef STATPANEL_CONTROLLER_H
#define STATPANEL_CONTROLLER_H


#include <QObject>

#include "statpanel.h"
#include "store.h"


class StatPanelController : public QObject {

    Q_OBJECT

public:
    StatPanelController(
        StatPanel* aView,
        Store&     aStore,
        QObject*   parent = nullptr
    );

    void onStateChanged();

private:
    StatPanel* mView;
    Store&     mStore;

};


#endif // STATPANEL_CONTROLLER_H
