#ifndef STATPANEL_CONTROLLER_H
#define STATPANEL_CONTROLLER_H


#include <QObject>

#include "statpanel.h"
#include "store.h"


class StatPanelController : QObject {

    Q_OBJECT

public:
    StatPanelController(
        StatBox* aStrView,
        StatBox* aDexView,
        StatBox* aConView,
        StatBox* aIntView,
        StatBox* aWisView,
        StatBox* aChaView,
        Store&   aStore,
        QObject* parent = nullptr
    );

private:
    StatBox* mStrView;
    StatBox* mDexView;
    StatBox* mConView;
    StatBox* mIntView;
    StatBox* mWisView;
    StatBox* mChaView;
    Store&   mStore;

};


#endif // STATPANEL_CONTROLLER_H
