#ifndef FEATUREPANEL_CONTROLLER_H
#define FEATUREPANEL_CONTROLLER_H


#include <QObject>

#include "featurepanel.h"
#include "store.h"


class FeaturePanelController : QObject {

    Q_OBJECT

public:
    FeaturePanelController(
        FeaturePanel* aView,
        Store&     aStore,
        QObject*   parent = nullptr
    );

private:
    FeaturePanel* mView;
    Store&     mStore;

};


#endif // FEATUREPANEL_CONTROLLER_H
