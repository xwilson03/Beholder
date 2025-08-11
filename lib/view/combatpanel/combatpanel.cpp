#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QWidget>

#include "panel.h"
#include "badge.h"
#include "combatpanel.h"


CombatPanel::CombatPanel(
    QWidget *parent
)
: Panel("Combat", parent)
{
    mContent = new QWidget();
    mContent->setObjectName("combatPanelContent");
    setContent(mContent);

    QGridLayout* layout = new QGridLayout();
    mContent->setLayout(layout);


    mHPLabel         = new QLabel("Hit Points");
    mTempHPLabel     = new QLabel("Temp HP");
    mACLabel         = new QLabel("Armor Class");
    mInitiativeLabel = new QLabel("Initiative");
    mSpeedLabel      = new QLabel("Speed");

    mHPBadge         = new Badge();
    mTempHPBadge     = new Badge();
    mACBadge         = new Badge();
    mInitiativeBadge = new Badge();
    mSpeedBadge      = new Badge();

    mSeparator       = new QFrame();


    mHPLabel->setObjectName("HPLabel");
    mTempHPLabel->setObjectName("tempHPLabel");
    mSeparator->setObjectName("separator");
    mSeparator->setFrameStyle(QFrame::HLine);
    mACLabel->setObjectName("armorClassLabel");
    mInitiativeLabel->setObjectName("initiativeLabel");
    mSpeedLabel->setObjectName("speedLabel");


    layout->addWidget(mHPLabel, 0, 0);
    layout->addWidget(mHPBadge, 0, 1, Qt::AlignRight);
    layout->addWidget(mTempHPLabel, 1, 0);
    layout->addWidget(mTempHPBadge, 1, 1, Qt::AlignRight);
    layout->addWidget(mSeparator, 2, 0, 1, 2);
    layout->addWidget(mACLabel, 3, 0);
    layout->addWidget(mACBadge, 3, 1, Qt::AlignRight);
    layout->addWidget(mInitiativeLabel, 4, 0);
    layout->addWidget(mInitiativeBadge, 4, 1, Qt::AlignRight);
    layout->addWidget(mSpeedLabel, 5, 0);
    layout->addWidget(mSpeedBadge, 5, 1, Qt::AlignRight);

}

void CombatPanel::setHP(int aValue) {
    mHP = aValue;
}

void CombatPanel::setMaxHP(int aValue) {
    mMaxHP = aValue;
}

void CombatPanel::setTempHP(int aValue) {
    mTempHP = aValue;
}

void CombatPanel::setAC(int aValue) {
    mAC = aValue;
}

void CombatPanel::setInitiative(int aValue) {
    mInitiative = aValue;
}

void CombatPanel::setSpeed(int aValue) {
    mSpeed = aValue;
}

void CombatPanel::updateHPBadge() {
    mHPBadge->setText(QString::number(mHP) + "/" + QString::number(mMaxHP));
}

void CombatPanel::updateTempHPBadge() {
    mTempHPBadge->setText(QString::number(mTempHP));
}

void CombatPanel::updateACBadge() {
    mACBadge->setText(QString::number(mAC));
}

void CombatPanel::updateInitiativeBadge() {
    mInitiativeBadge->setText("+" + QString::number(mInitiative));
}

void CombatPanel::updateSpeedBadge() {
    mSpeedBadge->setText(QString::number(mSpeed));
}
