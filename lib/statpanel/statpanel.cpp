#include <QLabel>
#include <QGridLayout>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include "statpanel.h"


StatPanel::StatPanel(
    QWidget *parent
)
: QWidget(parent)
{
    QGridLayout* layout = new QGridLayout(this);
    setLayout(layout);

    mStr = new StatBox("STR", 0, this);
    mDex = new StatBox("DEX", 0, this);
    mCon = new StatBox("CON", 0, this);
    mInt = new StatBox("INT", 0, this);
    mWis = new StatBox("WIS", 0, this);
    mCha = new StatBox("CHA", 0, this);

    layout->addWidget(mStr, 0, 0);
    layout->addWidget(mDex, 0, 1);
    layout->addWidget(mCon, 1, 0);
    layout->addWidget(mInt, 1, 1);
    layout->addWidget(mWis, 2, 0);
    layout->addWidget(mCha, 2, 1);
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

    setStyleSheet(
        "QFrame {"
        "    color: white;"
        "    background-color: purple;"
        "    border-radius: 15px;"
        "}"
    );

    QVBoxLayout* layout = new QVBoxLayout(this);
    setLayout(layout);

    mStatLabel = new QLabel(mStat.c_str(), this);
    mStatLabel->setAlignment(Qt::AlignHCenter);

    mValueLabel = new QLabel(QString::number(mValue), this);
    mValueLabel->setAlignment(Qt::AlignHCenter);

    layout->addWidget(mStatLabel);
    layout->addWidget(mValueLabel);
}
