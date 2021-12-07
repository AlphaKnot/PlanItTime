#ifndef ASTEROIDWIDGET_H
#define ASTEROIDWIDGET_H

#include <QLabel>

class AsteroidWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AsteroidWidget(QWidget *parent = nullptr);

private:
    void animateAsteroid();

signals:

};

#endif // ASTEROIDWIDGET_H
