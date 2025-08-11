#ifndef BADGE_H
#define BADGE_H

#include <QFrame>
#include <QLabel>
#include <QObject>
#include <QResizeEvent>
#include <QString>
#include <QWidget>


class Badge : public QFrame
{
    Q_OBJECT

public:
    explicit Badge(
        QWidget *parent = nullptr
    );

    void setText(QString aText);

private:
    QLabel* mTextLabel = nullptr;
};


#endif // BADGE_H
