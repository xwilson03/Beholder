#include <QFrame>
#include <QVBoxLayout>
#include <QResizeEvent>
#include <QWidget>

#include "badge.h"


Badge::Badge(
    QWidget *parent
)
: QFrame(parent)
{
    setObjectName("badge");

    QVBoxLayout* layout = new QVBoxLayout();
    setLayout(layout);

    layout->setContentsMargins(6,0,6,0);

    mTextLabel = new QLabel();
    mTextLabel->setObjectName("badgeText");

    layout->addWidget(mTextLabel);
}

void Badge::setText(QString aText) {
    mTextLabel->setText(aText);
}
