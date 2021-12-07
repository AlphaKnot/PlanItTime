#ifndef UISCREEN_H
#define UISCREEN_H

#include <QMainWindow>
#include<QWidget>
#include"solarwidget.h"
#include"timewidget.h"
#include"alarmwidget.h"
#include"asteroidwidget.h"
#include <QKeyEvent>
#include <QTimer>




QT_BEGIN_NAMESPACE
namespace Ui { class UIScreen; }
QT_END_NAMESPACE

class UIScreen : public QMainWindow
{
    Q_OBJECT

public:
    UIScreen(QWidget *parent = nullptr);
    ~UIScreen();


private:
    //void changeFace(bool& facevalue, TimeWidget*, SolarWidget*, AlarmWidget* );
   void keyPressEvent(QKeyEvent *event);
   void SoundAlarm();
    void alarmCheck();
    Ui::UIScreen *ui;
    TimeWidget *tw;
    AlarmWidget *aw;
    SolarWidget *sw;
    AsteroidWidget *asw;
    bool facevalue;



};
#endif // UISCREEN_H
