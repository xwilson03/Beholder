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
    QVBoxLayout* layout = new QVBoxLayout(this);
    setLayout(layout);

    mNameLabel = new QLabel(mName.c_str(), this);
    mSplashLabel = new QLabel(std::string (mClass + " " + std::to_string(aLevel) + " • " + aRace).c_str(), this);

    layout->addWidget(mNameLabel, 0, Qt::AlignHCenter);
    layout->addWidget(mSplashLabel, 0, Qt::AlignHCenter);
}
