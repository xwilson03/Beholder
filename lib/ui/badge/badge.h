#ifndef BADGE_H
#define BADGE_H

#include <QFrame>
#include <QLabel>
#include <QObject>
#include <QResizeEvent>
#include <QWidget>


class Badge : public QFrame
{
    Q_OBJECT

public:
    explicit Badge(
        std::string aText,
        QWidget *parent = nullptr
    );

private:
    QLabel* mTextLabel = nullptr;
};


#endif // BADGE_H
