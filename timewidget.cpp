#include "timewidget.h"
#include<QTimer>
#include<QTime>
#include<QFontDatabase>
#include<QDir>
#include<QDate>
#include<string>
#include<iostream>
/**
 * @brief TimeWidget::TimeWidget this class implements the time and date
 * @param parent the parent widget which it inherits from
 */
TimeWidget::TimeWidget(QWidget *parent) : QWidget(parent){

    // add the font
    QFontDatabase::addApplicationFont(QDir::currentPath()+"/fonts/ARCADECLASSIC.TTF"); //set your working dir as your actual working dir not build dir

    // set the style
    QPalette pal = QPalette();
    pal.setColor(QPalette::WindowText,Qt::cyan);

    // initialize the labels
    time_label = new QLabel(this);
    date_label = new QLabel(this);

    // setting the label font
    time_label->setFont(QFont("arcadeclassic",100)); // not case sensitive
    date_label->setFont(QFont("arcadeclassic",48));

    // setting the size
    date_label->setGeometry(360,300,400,100);
    time_label->setGeometry(350,340,400,100);

    // taking the style
    date_label->setPalette(pal);
    time_label->setPalette(pal);


    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&TimeWidget::showTime);
    timer->start(1000);

    showTime();
    resize(700,480);

}

/**
 * @brief TimeWidget::showTime this method gets the date and the time
 */
void TimeWidget::showTime(){

    std::string dateList[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

    std::string moList[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};

    QDateTime time = QDateTime::currentDateTime();

    // getting the current date and time
    int curr_month = time.toString("MM").toInt();
    int curr_year = time.toString("yyyy").toInt();
    int curr_day = time.toString("dd").toInt();


    QString time_text = time.toString("hh:mm");

    QDate date = QDate(curr_year,curr_month,curr_day);

    int day = date.dayOfWeek();

    // setting the date and time
    this->date_label->setText(QString::fromStdString(dateList[day-1]));
    this->time_label->setText(time_text);
}
