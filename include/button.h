#pragma once
#include <QPushButton>
#include <QPixmap>
#include <QMediaPlayer>
#include <QMediaContent>


class winButton : public QPushButton
{
    Q_OBJECT

public:
    winButton() = default;
    winButton(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;

public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonPixmapUp;
    QPixmap mButtonPixmapDown;
    QMediaPlayer *player;
    QMediaContent *song;
 
};