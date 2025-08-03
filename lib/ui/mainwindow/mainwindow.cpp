#include <QLayout>
#include <QMainWindow>
#include <QSplitter>
#include <QVBoxLayout>
#include <QWidget>

#include "mainwindow.h"
#include "nameplate.h"
#include "statpanel.h"
#include "store.h"
#include "combatpanel.h"


MainWindow::MainWindow(
    Store& aStore,
    QWidget *parent
)
: QMainWindow(parent)
, mStore(aStore)
{
    setObjectName("mainWindow");
    setWindowTitle("Beholder");

    QSplitter *centralWidget = new QSplitter(this);
    centralWidget->setObjectName("mainSplitter");
    setCentralWidget(centralWidget);


    std::string name;
    int         level;
    std::string characterClass;
    std::string race;

    {
        Store::Accessor state = mStore.getState();
        name = state->name;
        level = state->level;
        characterClass = state->characterClass;
        race = state->race;
    }

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

    );


    QWidget* leftSidebar = new QWidget(this);
    leftSidebar->setObjectName("sidebar");
    QVBoxLayout* leftLayout = new QVBoxLayout(leftSidebar);
    leftSidebar->setLayout(leftLayout);

    leftLayout->addWidget(
        new NamePlate(
            name,
            level,
            characterClass,
            race,
            leftSidebar
        )
    );

    leftLayout->addWidget(
        new StatPanel(
            leftSidebar
        )
    );

    leftLayout->addWidget(
        new CombatPanel(
            leftSidebar
        )
    );

    leftLayout->addStretch(1);


    QWidget *centralArea = new QWidget(this);


    QWidget *rightSidebar = new QWidget(this);
    rightSidebar->setObjectName("sidebar");
    QVBoxLayout* rightLayout = new QVBoxLayout(rightSidebar);
    rightSidebar->setLayout(rightLayout);

    rightLayout->addStretch(1);


    centralWidget->addWidget(leftSidebar);
    centralWidget->addWidget(centralArea);
    centralWidget->addWidget(rightSidebar);

    centralWidget->setStretchFactor(0,0);
    centralWidget->setStretchFactor(1,1);
    centralWidget->setStretchFactor(2,0);
}
