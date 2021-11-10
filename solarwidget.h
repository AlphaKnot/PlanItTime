#ifndef SOLARWIDGET_H
#define SOLARWIDGET_H

#include <QWidget>
#include <vector>
#include<QDateTime>
#include "OrbitalElements.h"

class SolarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SolarWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void computePosition();
private:
    QDateTime time_check;
    std::vector<OrbitalElements> planets;

signals:

};

#endif // SOLARWIDGET_H
