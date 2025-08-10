#ifndef STATPANEL_H
#define STATPANEL_H

#include <QFrame>
#include <QLabel>
#include <QObject>
#include <QWidget>

#include "panel.h"


class StatBox : public QFrame
{
    Q_OBJECT

public:
    explicit StatBox(
        std::string aStat,
        QWidget*    parent = nullptr
    );

    void setValue(int aValue);

private:

    std::string mStat  = "";
    int         mValue = 0;

    QLabel* mStatLabel  = nullptr;
    QLabel* mValueLabel = nullptr;
    QLabel* mModLabel   = nullptr;
};


class StatPanel : public Panel
{
    Q_OBJECT

public:
    explicit StatPanel(
        QWidget* parent = nullptr
    );

    void setStrength(int aValue);
    void setDexterity(int aValue);
    void setConstitution(int aValue);
    void setIntelligence(int aValue);
    void setWisdom(int aValue);
    void setCharisma(int aValue);

private:

    StatBox* mStr = nullptr;
    StatBox* mDex = nullptr;
    StatBox* mCon = nullptr;
    StatBox* mInt = nullptr;
    StatBox* mWis = nullptr;
    StatBox* mCha = nullptr;

    QWidget* mStatBoxes = nullptr;
};


#endif // STATPANEL_H
