#include <QFrame>
#include <QVBoxLayout>
#include <QResizeEvent>
#include <QWidget>

#include "badge.h"


Badge::Badge(
    std::string aText,
    QWidget *parent
)
: QFrame(parent)
{
    setObjectName("badge");

    QVBoxLayout* layout = new QVBoxLayout(this);
    setLayout(layout);

    layout->setContentsMargins(6,0,6,0);

    mTextLabel = new QLabel(aText.c_str(), this);
    mTextLabel->setObjectName("badgeText");

    layout->addWidget(mTextLabel);
}
