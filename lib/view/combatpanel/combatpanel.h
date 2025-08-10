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

private:

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
