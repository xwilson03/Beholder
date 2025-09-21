#include <QLayout>
#include <QMainWindow>
#include <QSplitter>
#include <QVBoxLayout>
#include <QWidget>

#include "mainwindow.h"
#include "nameplate.h"
#include "statpanel.h"
#include "combatpanel.h"
#include "featurepanel.h"
#include "inventorypanel.h"


MainWindow::MainWindow(
    NamePlate* aNamePlate,
    StatPanel* aStatPanel,
    CombatPanel* aCombatPanel,
    FeaturePanel* aFeaturePanel,
    InventoryPanel* aInventoryPanel,
    QWidget *parent
)
: QMainWindow(parent)
, mNamePlate(aNamePlate)
, mStatPanel(aStatPanel)
, mCombatPanel(aCombatPanel)
, mFeaturePanel(aFeaturePanel)
, mInventoryPanel(aInventoryPanel)
{
    setObjectName("mainWindow");
    setWindowTitle("Beholder");

    setStyleSheet(

        // Main Window

        "#mainWindow {"
            "background-color: white;"
            "min-width: 640px;"
            "min-height: 480px;"
        "}"

        "#sidebar {"
            "min-width: 180px;"
        "}"

        "#mainSplitter::handle {"
            "background-color: lightgray;"
            "width: 6px;"
            "height: 6px;"
        "}"

        // Name Plate

        "#namePlate {}"

        "#characterName {"
            "color: purple;"
        "}"

        "#characterSplash {"
            "color: dimgray;"
        "}"

        // Panel

        "#panel {"
            "background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 whitesmoke, stop: 1 gainsboro);"
            "border: 2px solid gainsboro;"
            "border-radius: 16px;"
        "}"

        "#panelTitle {"
            "color: purple;"
        "}"

        // Badge

        "#badge {"
            "background-color: whitesmoke;"
            "border: 2px solid gainsboro;"
            "border-radius: 10px;"
        "}"

        "#badgeText {"
            "color: black;"
        "}"

        // Stat Panel

        "#statPanelBoxes {}"

        "#statBox {"
            "background-color: purple;"
            "border-radius: 16px;"
        "}"

        "#statNameLabel {"
            "color: white;"
            "font-size: 14px;"
            "font: bold;"
        "}"

        "#statValueLabel {"
            "color: white;"
            "font-size: 20px;"
            "font: bold;"
        "}"

        "#statModLabel {"
            "color: white;"
            "font-size: 14px;"
        "}"

        // Combat Panel

        "combatPanelContent {}"

        "#HPLabel {"
            "color: black;"
        "}"

        "#tempHPLabel {"
            "color: black;"
        "}"

        "#separator {"
            "color: grey;"
        "}"

        "#armorClassLabel {"
            "color: black;"
        "}"

        "#initiativeLabel {"
            "color: black;"
        "}"

        "#speedLabel {"
            "color: black;"
        "}"

        // Feature Panel

        "featurePanelContent {}"

        "featureItem {}"

        "featureText {}"

        "#featureNameLabel {"
            "color: black;"
            "font-size: 14px;"
        "}"

        "#featureCategoryLabel {"
            "color: gray;"
            "font-size: 12px;"
        "}"

        // Inventory Panel

        "inventoryPanelContent {}"

        "inventoryItem {}"

        "inventoryText {}"

        "#inventoryNameLabel {"
            "color: black;"
            "font-size: 14px;"
        "}"

        "#inventoryCategoryLabel {"
            "color: gray;"
            "font-size: 12px;"
        "}"

    );


    QSplitter* splitter = new QSplitter();
    splitter->setObjectName("mainSplitter");
    setCentralWidget(splitter);


    QWidget* leftSidebar = new QWidget();
    leftSidebar->setObjectName("sidebar");
    QVBoxLayout* leftLayout = new QVBoxLayout();
    leftSidebar->setLayout(leftLayout);

    leftLayout->addWidget(mNamePlate);
    leftLayout->addWidget(mStatPanel);
    leftLayout->addWidget(mCombatPanel);

    leftLayout->addStretch(1);


    QWidget *centralArea = new QWidget();


    QWidget *rightSidebar = new QWidget();
    rightSidebar->setObjectName("sidebar");
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightSidebar->setLayout(rightLayout);

    rightLayout->addWidget(mFeaturePanel);
    rightLayout->addWidget(mInventoryPanel);

    rightLayout->addStretch(1);


    splitter->addWidget(leftSidebar);
    splitter->addWidget(centralArea);
    splitter->addWidget(rightSidebar);

    splitter->setStretchFactor(0,0);
    splitter->setStretchFactor(1,1);
    splitter->setStretchFactor(2,0);
}
