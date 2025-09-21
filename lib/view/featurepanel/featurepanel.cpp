#include <QHBoxLayout>
#include <QVBoxLayout>

#include "panel.h"
#include "badge.h"
#include "featurepanel.h"


FeaturePanel::FeaturePanel(
    QWidget *parent
)
: Panel("Features & Traits", parent)
{
    mContent = new QWidget();
    mContent->setObjectName("featurePanelContent");
    setContent(mContent);

    QVBoxLayout* layout = new QVBoxLayout();
    mContent->setLayout(layout);

    layout->setSpacing(0);
}

void FeaturePanel::clearFeatures() {
    QLayoutItem* item = nullptr;
    while ((item = mContent->layout()->takeAt(0)) != nullptr) {
        assert(!item->layout());
        dynamic_cast<QWidget*>(item)->deleteLater();
    }
}

void FeaturePanel::addFeature(
    std::string name,
    std::string category,
    bool passive,
    uint8_t charges,
    uint8_t maxCharges
)
{
    QWidget* featureItem = new QWidget();
    featureItem->setObjectName("featureItem");

    QHBoxLayout* featureItemLayout = new QHBoxLayout();
    featureItemLayout->setContentsMargins(0,0,0,0);
    featureItem->setLayout(featureItemLayout);

    QWidget* featureText = new QWidget();
    featureText->setObjectName("featureText");

    QVBoxLayout* featureTextLayout = new QVBoxLayout();
    featureText->setLayout(featureTextLayout);

    QLabel* featureLabel = new QLabel(name.c_str());
    featureLabel->setObjectName("featureNameLabel");

    QLabel* featureCategoryLabel = new QLabel(category.c_str());
    featureCategoryLabel->setObjectName("featureCategoryLabel");

    featureTextLayout->addWidget(featureLabel);
    featureTextLayout->addWidget(featureCategoryLabel);

    Badge* featureBadge = new Badge();
    featureBadge->setText(
        passive ? "Passive"
        : std::string(std::to_string(charges) + "/" + std::to_string(maxCharges)).c_str()
    );

    featureItemLayout->addWidget(featureText);
    featureItemLayout->addStretch();
    featureItemLayout->addWidget(featureBadge, 0, Qt::AlignVCenter);

    mContent->layout()->addWidget(featureItem);
}
