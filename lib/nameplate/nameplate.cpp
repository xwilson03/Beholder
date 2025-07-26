#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include "nameplate.h"


NamePlate::NamePlate(
    std::string aName,
    int         aLevel,
    std::string aClass,
    std::string aRace,
    QWidget *parent
)
: QWidget(parent)
, mName(aName)
, mLevel(aLevel)
, mClass(aClass)
, mRace(aRace)
{
    setObjectName("namePlate");

    QVBoxLayout* layout = new QVBoxLayout(this);
    setLayout(layout);

    mNameLabel = new QLabel(mName.c_str(), this);
    mNameLabel->setObjectName("characterName");
    mSplashLabel = new QLabel(std::string (mClass + " " + std::to_string(aLevel) + " • " + aRace).c_str(), this);
    mSplashLabel->setObjectName("characterSplash");

    layout->addWidget(mNameLabel, 0, Qt::AlignHCenter);
    layout->addWidget(mSplashLabel, 0, Qt::AlignHCenter);
}
