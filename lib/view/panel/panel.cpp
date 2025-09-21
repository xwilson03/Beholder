#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#include "panel.h"


Panel::Panel(
    std::string aTitle,
    QWidget *parent
)
: QFrame(parent)
{
    setObjectName("panel");

    setStyleSheet(
        "#panel {"
            "background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 whitesmoke, stop: 1 gainsboro);"
            "border: 2px solid gainsboro;"
            "border-radius: 16px;"
        "}"

        "#panelTitle {"
            "color: purple;"
        "}"
    );

    QVBoxLayout* layout = new QVBoxLayout(this);
    setLayout(layout);

    mTitleLabel = new QLabel(aTitle.c_str(), this);
    mTitleLabel->setObjectName("panelTitle");
    layout->addWidget(mTitleLabel);
}

void Panel::setContent(QWidget* aContent)
{
    if (mContent != nullptr) {
        layout()->removeWidget(mContent);
        layout()->deleteLater();
    }

    mContent = aContent;
    layout()->addWidget(mContent);
}
