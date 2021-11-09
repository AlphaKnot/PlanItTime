#ifndef SOLARWIDGET_H
#define SOLARWIDGET_H

#include <QWidget>
#include <QLabel>

class TimeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TimeWidget(QWidget *parent = nullptr);

private slots:
     void showTime();
private:
     QLabel *time_label;
     QLabel *date_label;

signals:

};

#endif // SOLARWIDGET_H
