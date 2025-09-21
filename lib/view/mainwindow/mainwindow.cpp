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
#include "spellpanel.h"


MainWindow::MainWindow(
    NamePlate* aNamePlate,
    StatPanel* aStatPanel,
    CombatPanel* aCombatPanel,
    FeaturePanel* aFeaturePanel,
    InventoryPanel* aInventoryPanel,
    SpellPanel* aSpellPanel,
    QWidget *parent
)
: QMainWindow(parent)
, mNamePlate(aNamePlate)
, mStatPanel(aStatPanel)
, mCombatPanel(aCombatPanel)
, mFeaturePanel(aFeaturePanel)
, mInventoryPanel(aInventoryPanel)
, mSpellPanel(aSpellPanel)
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
    rightLayout->addWidget(mSpellPanel);

    rightLayout->addStretch(1);


    splitter->addWidget(leftSidebar);
    splitter->addWidget(centralArea);
    splitter->addWidget(rightSidebar);

    splitter->setStretchFactor(0,0);
    splitter->setStretchFactor(1,1);
    splitter->setStretchFactor(2,0);
}
