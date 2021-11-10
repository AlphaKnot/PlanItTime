#ifndef UISCREEN_H
#define UISCREEN_H

#include <QMainWindow>
#include<QWidget>
#include"solarwidget.h"
#include"timewidget.h"
#include"alarmwidget.h"




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
    Ui::UIScreen *ui;
    TimeWidget *tw;
    AlarmWidget *aw;
    SolarWidget *sw;


};
#endif // UISCREEN_H
