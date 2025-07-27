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
    Badge*  mHPBadge;
    QLabel* mTempHPLabel;
    Badge*  mTempHPBadge;
    QFrame* mSeparator;
    QLabel* mACLabel;
    Badge*  mACBadge;
    QLabel* mInitiativeLabel;
    Badge*  mInitiativeBadge;
    QLabel* mSpeedLabel;
    Badge*  mSpeedBadge;

};


#endif // COMBATPANEL_H
