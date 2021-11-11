#include "timewidget.h"
#include<QTimer>
#include<QTime>
#include<QFontDatabase>
#include<QDir>
#include<QDate>
#include<string>

TimeWidget::TimeWidget(QWidget *parent) : QWidget(parent){

    QFontDatabase::addApplicationFont(QDir::currentPath()+"/fonts/ARCADECLASSIC.TTF"); //set your working dir as your actual working dir not build dir


    QPalette pal = QPalette();
    pal.setColor(QPalette::WindowText,Qt::cyan);

    time_label = new QLabel(this);
    date_label = new QLabel(this);


    time_label->setFont(QFont("arcadeclassic",100)); // not case sensitive
    date_label->setFont(QFont("arcadeclassic",48));

    date_label->setGeometry(360,300,400,100);
    time_label->setGeometry(350,340,400,100);

    date_label->setPalette(pal);
    time_label->setPalette(pal);


    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&TimeWidget::showTime);
    timer->start(1000);

    showTime();
    resize(600,500);

}
void TimeWidget::showTime(){

    std::string dateList[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

    std::string moList[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};


    QDateTime time = QDateTime::currentDateTime();


    int curr_month = time.toString("MM").toInt();
    int curr_year = time.toString("yyyy").toInt();
    int curr_day = time.toString("dd").toInt();


    QString time_text = time.toString("hh:mm");

    QDate date = QDate(curr_year,curr_month,curr_day);
    int day = date.dayOfWeek();

    this->date_label->setText(QString::fromStdString(dateList[day]));
    this->time_label->setText(time_text);
}
