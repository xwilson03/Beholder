#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include "nameplate.h"


NamePlate::NamePlate(
    QWidget *parent
)
: QWidget(parent)
{
    setObjectName("namePlate");

    setStyleSheet(
        "#namePlate {}"

        "#characterName {"
            "color: purple;"
        "}"

        "#characterSplash {"
            "color: dimgray;"
        "}"
    );

    QVBoxLayout* layout = new QVBoxLayout(this);
    setLayout(layout);

    mNameLabel = new QLabel();
    mSplashLabel = new QLabel();

    mNameLabel->setObjectName("characterName");
    mSplashLabel->setObjectName("characterSplash");

    layout->addWidget(mNameLabel, 0, Qt::AlignHCenter);
    layout->addWidget(mSplashLabel, 0, Qt::AlignHCenter);
}

void NamePlate::setName(std::string aName)
{
    mName = aName;
}

void NamePlate::setLevel(int aLevel)
{
    mLevel = aLevel;
}

void NamePlate::setClass(std::string aClass)
{
    mClass = aClass;
}

void NamePlate::setRace(std::string aRace)
{
    mRace = aRace;
}

void NamePlate::updateNameLabel() {
    mNameLabel->setText(mName.c_str());
}

void NamePlate::updateSplashLabel() {
    mSplashLabel->setText(std::string (mClass + " " + std::to_string(mLevel) + " • " + mRace).c_str());
}
