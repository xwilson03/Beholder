#include <QFrame>
#include <QLabel>
#include <QGridLayout>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include "panel.h"
#include "statpanel.h"


StatPanel::StatPanel(
    QWidget* parent
)
: Panel("Ability Scores", parent)
{
    mStatBoxes = new QWidget(this);
    mStatBoxes->setObjectName("statPanelBoxes");
    setContent(mStatBoxes);

    QGridLayout* boxLayout = new QGridLayout(mStatBoxes);
    mStatBoxes->setLayout(boxLayout);

    mStr = new StatBox("STR");
    mDex = new StatBox("DEX");
    mCon = new StatBox("CON");
    mInt = new StatBox("INT");
    mWis = new StatBox("WIS");
    mCha = new StatBox("CHA");

    boxLayout->addWidget(mStr, 0, 0);
    boxLayout->addWidget(mDex, 0, 1);
    boxLayout->addWidget(mCon, 1, 0);
    boxLayout->addWidget(mInt, 1, 1);
    boxLayout->addWidget(mWis, 2, 0);
    boxLayout->addWidget(mCha, 2, 1);
}

void StatPanel::setStrength(int aValue) {
    mStr->setValue(aValue);
}

void StatPanel::setDexterity(int aValue) {
    mDex->setValue(aValue);
}

void StatPanel::setConstitution(int aValue) {
    mCon->setValue(aValue);
}

void StatPanel::setIntelligence(int aValue) {
    mInt->setValue(aValue);
}

void StatPanel::setWisdom(int aValue) {
    mWis->setValue(aValue);
}

void StatPanel::setCharisma(int aValue) {
    mCha->setValue(aValue);
}


StatBox::StatBox(
    std::string aStat,
    QWidget*    parent
)
: QFrame(parent)
, mStat(aStat)
{
    setObjectName("statBox");

    QVBoxLayout* layout = new QVBoxLayout(this);
    setLayout(layout);

    mStatLabel = new QLabel(mStat.c_str(), this);
    mStatLabel->setObjectName("statNameLabel");
    mStatLabel->setAlignment(Qt::AlignHCenter);

    mValueLabel = new QLabel();
    mValueLabel->setObjectName("statValueLabel");
    mValueLabel->setAlignment(Qt::AlignHCenter);

    mModLabel = new QLabel();
    mModLabel->setObjectName("statModLabel");
    mModLabel->setAlignment(Qt::AlignHCenter);

    layout->addWidget(mStatLabel);
    layout->addWidget(mValueLabel);
    layout->addWidget(mModLabel);
}

void StatBox::setValue(int aValue) {
    mValue = aValue;
    mValueLabel->setText(QString::number(mValue));
    mModLabel->setText(QString::number((aValue - 10) / 2));
}
