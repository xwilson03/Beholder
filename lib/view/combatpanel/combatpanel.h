#ifndef COMBATPANEL_H
#define COMBATPANEL_H

#include <QObject>
#include <QWidget>

#include "panel.h"
#include "badge.h"


class CombatPanel : public Panel
{
    Q_OBJECT

public:
    explicit CombatPanel(QWidget *parent = nullptr);

    void setHP(int aValue);
    void setMaxHP(int aValue);
    void setTempHP(int aValue);
    void setAC(int aValue);
    void setInitiative(int aValue);
    void setSpeed(int aValue);

    void updateHPBadge();
    void updateTempHPBadge();
    void updateACBadge();
    void updateInitiativeBadge();
    void updateSpeedBadge();

private:

    int mHP = 0;
    int mMaxHP = 0;
    int mTempHP = 0;
    int mAC = 0;
    int mInitiative = 0;
    int mSpeed = 0;

    QWidget* mContent;

    QLabel* mHPLabel;
    QLabel* mTempHPLabel;
    QLabel* mACLabel;
    QLabel* mInitiativeLabel;
    QLabel* mSpeedLabel;

    Badge*  mHPBadge;
    Badge*  mTempHPBadge;
    Badge*  mACBadge;
    Badge*  mInitiativeBadge;
    Badge*  mSpeedBadge;

    QFrame* mSeparator;

};


#endif // COMBATPANEL_H
