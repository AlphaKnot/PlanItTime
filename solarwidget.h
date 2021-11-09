#ifndef SOLARWIDGET_H
#define SOLARWIDGET_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include "Planets.h"
#include "OrbitalElements.h"

class SolarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SolarWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
private:
    void initSystem();
    QLabel* sunLabel;
    Planets *p;
    std::vector<OrbitalElements> planets;


signals:

};

#endif // SOLARWIDGET_H
