#include "featurepanel_controller.h"

#include "store.h"
#include <iostream>

FeaturePanelController::FeaturePanelController(
    FeaturePanel* aView,
    Store&     aStore,
    QObject*   parent
)
: QObject(parent)
, mView(aView)
, mStore(aStore)
{

    std::vector<State::Feature> features = {};
    {
        auto state = mStore.getState();
        features = state->features;
    }

    mView->clearFeatures();
    for (const auto feature : features) {
        mView->addFeature(
            feature.name,
            feature.category,
            feature.passive,
            feature.charges,
            feature.maxCharges
        );
    }
}
