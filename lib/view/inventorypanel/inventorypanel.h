#ifndef INVENTORYPANEL_H
#define INVENTORYPANEL_H

#include <QObject>
#include <QWidget>

#include "panel.h"
#include "badge.h"


class InventoryPanel : public Panel
{
    Q_OBJECT

public:
    explicit InventoryPanel(QWidget *parent = nullptr);

    void clearItems();
    void addItem(
        std::string name,
        std::string category,
        bool equipped
    );

private:

    QWidget* mContent;

};


#endif // INVENTORYPANEL_H
