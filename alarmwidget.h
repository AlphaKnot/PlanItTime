#ifndef ALARMWIDGET_H
#define ALARMWIDGET_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QGraphicsOpacityEffect>
#include <iostream>
#include <fstream>
#include <QLabel>
#include <QGridLayout>
#include <QFontDatabase>
#include <QPushButton>
#include <QDir>
#include <QLabel>
#include <QListWidget>
#include <boost/algorithm/string.hpp>
#include <QComboBox>
class AlarmWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AlarmWidget(QWidget *parent = nullptr);
    void addButtonClicked();
    void removeButtonClicked();
    void itemClicked();
    void delete_line(char* , int );
    std::vector<std::string> getTimes();
signals:

private:
    void readTimeSlots(std::string&,  QListWidget* alarmList);
    bool checkFile (std::string&);
    QListWidget* alarmList;
    QPushButton* add_alarm;
    QPushButton* remove_alarm;
    QComboBox* hour_box;
    QComboBox* minute_box;
    QComboBox* AM_PM_Box;
    std::vector<std::string> Times;

};

#endif // ALARMWIDGET_H
