#ifndef NAMEPLATE_H
#define NAMEPLATE_H

#include <QLabel>
#include <QWidget>


class NamePlate : public QWidget
{
    Q_OBJECT

public:
    explicit NamePlate(
        std::string aName,
        int         aLevel,
        std::string aClass,
        std::string aRace,
        QWidget *parent = nullptr
    );

private:
    std::string mName;
    int         mLevel;
    std::string mClass;
    std::string mRace;

    QLabel* mNameLabel;
    QLabel* mSplashLabel;
};

#endif // NAMEPLATE_H
