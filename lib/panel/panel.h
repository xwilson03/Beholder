#ifndef PANEL_H
#define PANEL_H

#include <QFrame>
#include <QLabel>
#include <QObject>
#include <QWidget>


class Panel : public QFrame
{
    Q_OBJECT

public:
    explicit Panel(
        std::string aTitle,
        QWidget *parent = nullptr
    );

    void setContent(QWidget *aContent);

private:

    QLabel* mTitleLabel;
    QWidget* mContent;
};


#endif // PANEL_H
