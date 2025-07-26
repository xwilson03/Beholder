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
    }

    mContent = aContent;
    layout()->addWidget(mContent);
}
