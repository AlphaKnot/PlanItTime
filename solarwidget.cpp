#include<QPainter>
#include<QDir>
#include<string>
#include<QTimer>
#include <QLabel>
#include "solarwidget.h"
#include "Planets.h"

SolarWidget::SolarWidget(QWidget *parent) : QWidget(parent){

    time_check = time_check.currentDateTime().addYears(-1);

    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&SolarWidget::computePosition);
    timer->start(1);

    computePosition();
    QWidget::update();

    resize(600,500);

}
void SolarWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setPen(Qt::darkGray);
    for (int i = 1; i < 9; i++){
        painter.drawEllipse(QPoint(210,210),i*25,i*25);
    }
}
void SolarWidget::computePosition(){

    QDateTime dateTime;
    dateTime = dateTime.currentDateTime();

    if (dateTime.toString("yyyyMddhhmm").toDouble() > time_check.toString("yyyyMddhhmm").toDouble()){

        // delete all prior labels
        while (QWidget* w = findChild<QWidget*>()){
            delete w;
        }

        // compute planets given time
        Planets p = Planets(
                    dateTime.toString("yyyy").toDouble(),
                    dateTime.toString("MM").toDouble(),
                    dateTime.toString("dd").toDouble(),
                    dateTime.toString("H").toDouble(),
                    dateTime.toString("mm").toDouble()
                    );

        // set OrbitalElements vector
        planets = p.getPlanets();
        std::string planetList[8] = {"mercury","venus","earth","mars","jupiter","saturn","uranus","neptune"};

        for (int i = 0; i < planets.size(); i++){
            QLabel* planet = new QLabel(this);

            OrbitalElements current_planet = planets.at(i);

            planet->setGeometry(current_planet.getEclipX()+200,(-current_planet.getEclipY())+200,20,20);
            QPixmap pixmap = QPixmap(QDir::currentPath()+"/assets/"+QString::fromStdString(planetList[i])+".png");
            planet->setPixmap(pixmap.scaled(20,20));
            planet->show();

        }

        QLabel* sunLabel = new QLabel(this);
        sunLabel->setGeometry(200,200,24,24);
        QPixmap pixmap = QPixmap(QDir::currentPath()+"/assets/sun.png");
        sunLabel->setPixmap(pixmap.scaled(24,24));

        sunLabel->show();
        time_check = dateTime;

    }


}
