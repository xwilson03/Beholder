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
    mContent = new QWidget(this);
    mContent->setObjectName("combatPanelContent");
    setContent(mContent);

    QGridLayout* layout = new QGridLayout(mContent);
    mContent->setLayout(layout);

    mHPLabel = new QLabel("Hit Points", mContent);
    mHPLabel->setObjectName("HPLabel");

    mHPBadge = new Badge("42/58", mContent);

    mTempHPLabel = new QLabel("Temp HP", mContent);
    mTempHPLabel->setObjectName("tempHPLabel");

    mTempHPBadge = new Badge("5", mContent);

    mSeparator = new QFrame(mContent);
    mSeparator->setObjectName("separator");
    mSeparator->setFrameStyle(QFrame::HLine);

    mACLabel = new QLabel("Armor Class", mContent);
    mACLabel->setObjectName("armorClassLabel");

    mACBadge = new Badge("16", mContent);

    mInitiativeLabel = new QLabel("Initiative", mContent);
    mInitiativeLabel->setObjectName("initiativeLabel");

    mInitiativeBadge = new Badge("+2", mContent);

    mSpeedLabel = new QLabel("Speed", mContent);
    mSpeedLabel->setObjectName("speedLabel");

    mSpeedBadge = new Badge("30ft", mContent);

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
