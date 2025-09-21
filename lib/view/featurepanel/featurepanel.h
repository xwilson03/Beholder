#ifndef FEATUREPANEL_H
#define FEATUREPANEL_H

#include <QObject>
#include <QWidget>

#include "panel.h"
#include "badge.h"


class FeaturePanel : public Panel
{
    Q_OBJECT

public:
    explicit FeaturePanel(QWidget *parent = nullptr);

    void clearFeatures();
    void addFeature(
        std::string name,
        std::string category,
        bool passive,
        uint8_t charges,
        uint8_t maxCharges
    );

private:

    QWidget* mContent;

};


#endif // FEATUREPANEL_H
