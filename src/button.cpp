#include "button.h"
#include <iostream>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>


winButton::winButton(QWidget *parent) : QPushButton(parent)
{
    player = new QMediaPlayer;
   song = new QMediaContent(QUrl::fromLocalFile("../audio/btn.mp3"));
    player->setMedia(*song);
    player->setVolume(100);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonPixmapUp = QPixmap("../img/buttonUp.jpg");
    mButtonPixmapDown = QPixmap("../img/buttonDown.jpg");
    mCurrentButtonPixmap = mButtonPixmapUp;
    setGeometry(mCurrentButtonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &winButton::setDown);
    setFixedSize(100, 100);
}

void winButton::paintEvent(QPaintEvent *e)
{
   
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap); 
}

//Возвращяет размер веджета
QSize winButton::sizeHint() const
{
    return QSize(100, 100); 
}

//Возвращяет минимальный размер виджета
QSize winButton::minimumSizeHint() const
{
    return sizeHint();  
}

//Реакция на нажатие клавиатуры
void winButton::keyPressEvent(QKeyEvent *e)
{
    Q_UNUSED(e)
    setDown();
}

void winButton::setDown()
{
    player->play();
    mCurrentButtonPixmap = mButtonPixmapDown;
    update();//Перерисовывает виджет

    QTimer::singleShot(100, this, &winButton::setUp);
}

void winButton::setUp()
{
    mCurrentButtonPixmap = mButtonPixmapUp;
    update();
}
