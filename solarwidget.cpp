#include "solarwidget.h"
#include <QRectF>
#include<QPainter>
#include<QDir>
#include <iostream>
#include<string>

SolarWidget::SolarWidget(QWidget *parent) : QWidget(parent){
    initSystem();
    resize(600,500);
}
void SolarWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setPen(Qt::gray);
    for (int i = 1; i < 9; i++){
        painter.drawEllipse(QPoint(210,210),i*25,i*25);
    }
}
void SolarWidget::initSystem(){

    QDateTime dateTime;
    dateTime = dateTime.currentDateTime();

    std::cout << dateTime.toString("yyyy").toDouble() << " " << dateTime.toString("MM").toDouble() << " " << dateTime.toString("dd").toDouble() << " " << dateTime.toString("H").toDouble() << " " << dateTime.toString("mm").toDouble() << "\n";

    p = new Planets(
                2021,
                11,
                9,
                15,
                49
                );

    planets = p->getPlanets();
    std::string planetList[] = {"mercury","venus","earth","mars","jupiter","saturn","uranus","neptune"};
    for (int i = 0; i < planets.size(); i++){

        QLabel *planet = new QLabel(this);
        OrbitalElements current_planet = planets.at(i);
        planet->setGeometry(current_planet.getEclipX()+200,(-current_planet.getEclipY())+200,20,20);
        QPixmap pixmap = QPixmap(QDir::currentPath()+"/assets/"+QString::fromStdString(planetList[i])+".png");
        planet->setPixmap(pixmap.scaled(20,20));
        planet->show();

    }

    QWidget::update();

    sunLabel = new QLabel(this);
    sunLabel->setGeometry(200,200,20,20);
    QPixmap pixmap = QPixmap(QDir::currentPath()+"/assets/sun.png");
    sunLabel->setPixmap(pixmap.scaled(20,20));

    sunLabel->show();

}
