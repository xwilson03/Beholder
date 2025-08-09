#ifndef NAMEPLATE_H
#define NAMEPLATE_H

#include <QLabel>
#include <QWidget>


class NamePlate : public QWidget
{
    Q_OBJECT

public:
    explicit NamePlate(
        QWidget *parent = nullptr
    );

    void setName  (std::string aName);
    void setLevel (int         aLevel);
    void setClass (std::string aClass);
    void setRace  (std::string aRace);

    void updateNameLabel();
    void updateSplashLabel();

private:
    std::string mName  = "";
    int         mLevel = 0;
    std::string mClass = "";
    std::string mRace  = "";

    QLabel* mNameLabel   = nullptr;
    QLabel* mSplashLabel = nullptr;
};

#endif // NAMEPLATE_H
