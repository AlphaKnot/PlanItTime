#include "timewidget.h"
#include<QTimer>
#include<QTime>
#include<QFontDatabase>
#include<iostream>
#include<QDir>
TimeWidget::TimeWidget(QWidget *parent) : QWidget(parent){
    int id = QFontDatabase::addApplicationFont(QDir::currentPath()+"/fonts/ARCADECLASSIC.TTF"); //set your working dir as your actual working dir not build dir
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont arcadeclassic(family);

    time_label = new QLabel(this);
    date_label = new QLabel(this);
    date_label->resize(100,100); // needs to be formatted properly

    time_label->setFont(QFont("arcadeclassic",100));
    date_label->setFont(QFont("arcadeclassic",100));

    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&TimeWidget::showTime);
    timer->start(1000);

    showTime();
    resize(500,500);

}
void TimeWidget::showTime(){
    QDateTime time = QDateTime::currentDateTime();
    QString time_text = time.toString("h:mm:ss ap");
    QString date_text = time.toString("dd.MM.yyyy"); // we could convert this later
    // need day of week
    this->date_label->setText(date_text);
    this->time_label->setText(time_text);
}
