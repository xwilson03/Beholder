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
        int         aValue,
        QWidget *parent = nullptr
    );

private:

    int computeMod(int aValue);

    std::string mStat  = "";
    int         mValue = 0;

    QLabel* mStatLabel  = nullptr;
    QLabel* mValueLabel = nullptr;
    QLabel* mModLabel = nullptr;
};


class StatPanel : public Panel
{
    Q_OBJECT

public:
    explicit StatPanel(QWidget *parent = nullptr);

private:

    QWidget* mStatBoxes = nullptr;

    StatBox* mStr = nullptr;
    StatBox* mDex = nullptr;
    StatBox* mCon = nullptr;
    StatBox* mInt = nullptr;
    StatBox* mWis = nullptr;
    StatBox* mCha = nullptr;
};


#endif // STATPANEL_H
