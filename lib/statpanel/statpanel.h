#ifndef STATPANEL_H
#define STATPANEL_H

#include <QFrame>
#include <QLabel>
#include <QObject>
#include <QWidget>


class StatBox : public QFrame
{
    Q_OBJECT

public:
    explicit StatBox(
        std::string aStat,
        int         aValue,
        QWidget *parent = nullptr
    );

private:
    std::string mStat;
    int         mValue;

    QLabel* mStatLabel;
    QLabel* mValueLabel;
};


class StatPanel : public QWidget
{
    Q_OBJECT

public:
    explicit StatPanel(QWidget *parent = nullptr);

private:
    StatBox* mStr;
    StatBox* mDex;
    StatBox* mCon;
    StatBox* mInt;
    StatBox* mWis;
    StatBox* mCha;
};


#endif // STATPANEL_H
