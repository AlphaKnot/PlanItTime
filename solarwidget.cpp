#include<QPainter>
#include<QDir>
#include<string>
#include<QTimer>
#include <QLabel>
#include "solarwidget.h"
#include "Planets.h"

#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
/**
 * @brief SolarWidget::SolarWidget this class implements the solar system of the ui as well as the asteroid
 * @param parent the parent widget which it inherits from
 */
SolarWidget::SolarWidget(QWidget *parent) : QWidget(parent){

    time_check = time_check.currentDateTime().addYears(-1);

    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&SolarWidget::computePosition);
    timer->start(1);

    computePosition();
    QWidget::update();

    resize(600,500);

}
/**
 * @brief SolarWidget::paintEvent this widget paints the solar system rings
 * @param event the painting event
 */
void SolarWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setPen(Qt::darkGray);
    for (int i = 1; i < 9; i++){
        painter.drawEllipse(QPoint(210,210),i*25,i*25);
    }
}

/**
 * @brief SolarWidget::computePosition this method adds the planets to the system and animates them to be in real time. it also animates the asteroids
 */
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
            QPixmap pixmap = QPixmap(":/assets/"+QString::fromStdString(planetList[i])+".png");
            planet->setPixmap(pixmap.scaled(20,20));
            planet->show();

        }

        QLabel* sunLabel = new QLabel(this);
        sunLabel->setGeometry(200,200,24,24);
        QPixmap pixmap = QPixmap(":/assets/sun.png");
        sunLabel->setPixmap(pixmap.scaled(24,24));

        sunLabel->show();


        // this code is resposible for animating the asteroid
        // get the graphics
        QLabel* asteroidLabelI = new QLabel(this);
        asteroidLabelI->setGeometry(200,200, 50, 50);
        QPixmap pixmapp = QPixmap(QDir::currentPath()+"/assets/asteroid.png");
        asteroidLabelI->setPixmap(pixmapp.scaled(25,25));

        // creates the animation
        QPropertyAnimation *animationI = new QPropertyAnimation(asteroidLabelI, "geometry");
        animationI->setDuration(10000);
        animationI->setLoopCount(-1);
        animationI->setStartValue(QRect(0, 0, 400, 200));
        animationI->setKeyValueAt(1,QRect(rand()% 200 , rand() % 200, 500, 200));
        animationI->setEndValue(QRect(250, 250, 200, 200));
        animationI->start();

        time_check = dateTime;

    }

}

