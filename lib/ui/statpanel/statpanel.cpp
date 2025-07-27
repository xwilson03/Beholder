#include <QFrame>
#include <QLabel>
#include <QGridLayout>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include "panel.h"
#include "statpanel.h"


StatPanel::StatPanel(
    QWidget *parent
)
: Panel("Ability Scores", parent)
{
    mStatBoxes = new QWidget(this);
    mStatBoxes->setObjectName("statPanelBoxes");
    setContent(mStatBoxes);

    QGridLayout* boxLayout = new QGridLayout(mStatBoxes);
    mStatBoxes->setLayout(boxLayout);

    mStr = new StatBox("STR", 0, mStatBoxes);
    mDex = new StatBox("DEX", 0, mStatBoxes);
    mCon = new StatBox("CON", 0, mStatBoxes);
    mInt = new StatBox("INT", 0, mStatBoxes);
    mWis = new StatBox("WIS", 0, mStatBoxes);
    mCha = new StatBox("CHA", 0, mStatBoxes);

    boxLayout->addWidget(mStr, 0, 0);
    boxLayout->addWidget(mDex, 0, 1);
    boxLayout->addWidget(mCon, 1, 0);
    boxLayout->addWidget(mInt, 1, 1);
    boxLayout->addWidget(mWis, 2, 0);
    boxLayout->addWidget(mCha, 2, 1);
}


StatBox::StatBox(
    std::string aStat,
    int         aValue,
    QWidget *parent
)
: QFrame(parent)
, mStat(aStat)
, mValue(aValue)
{
    setObjectName("statBox");

    QVBoxLayout* layout = new QVBoxLayout(this);
    setLayout(layout);

    mStatLabel = new QLabel(mStat.c_str(), this);
    mStatLabel->setObjectName("statNameLabel");
    mStatLabel->setAlignment(Qt::AlignHCenter);

    mValueLabel = new QLabel(QString::number(mValue), this);
    mValueLabel->setObjectName("statValueLabel");
    mValueLabel->setAlignment(Qt::AlignHCenter);

    mModLabel = new QLabel(QString::number(computeMod(mValue)), this);
    mModLabel->setObjectName("statModLabel");
    mModLabel->setAlignment(Qt::AlignHCenter);

    layout->addWidget(mStatLabel);
    layout->addWidget(mValueLabel);
    layout->addWidget(mModLabel);
}

int StatBox::computeMod(int aValue)
{
    return (aValue - 10) / 2;
}
