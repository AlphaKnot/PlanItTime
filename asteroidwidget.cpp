#include "asteroidwidget.h"
#include<QLabel>
#include<QDir>
#include<QPropertyAnimation>
AsteroidWidget::AsteroidWidget(QWidget *parent) : QWidget(parent){

    animateAsteroid();
    resize(600,500);

}
void AsteroidWidget::animateAsteroid(){
    QLabel* asteroidLabelI = new QLabel(this);
    asteroidLabelI->setGeometry(200,200, 50, 50);
    QPixmap pixmapp = QPixmap(":/assets/asteroid.png");
    asteroidLabelI->setPixmap(pixmapp.scaled(25,25));
    QPropertyAnimation *animationI = new QPropertyAnimation(asteroidLabelI, "geometry");
    animationI->setDuration(10000);
    animationI->setLoopCount(-1);
    animationI->setStartValue(QRect(0, 0, 400, 200));
    animationI->setKeyValueAt(1,QRect(rand()% 200 , rand() % 200, 500, 200));
    animationI->setEndValue(QRect(700, 500, 200, 200));
    animationI->start();
}
