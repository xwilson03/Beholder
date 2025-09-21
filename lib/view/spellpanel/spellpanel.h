#ifndef SPELLPANEL_H
#define SPELLPANEL_H

#include <QObject>
#include <QWidget>

#include "panel.h"
#include "badge.h"


class SpellPanel : public Panel
{
    Q_OBJECT

public:
    explicit SpellPanel(QWidget *parent = nullptr);

    void clearSpellLevels();
    void addSpellLevel(
        uint8_t level,
        uint8_t spellSlots,
        uint8_t maxSpellSlots
    );

private:

    QWidget* mContent;

};


#endif // SPELLPANEL_H
