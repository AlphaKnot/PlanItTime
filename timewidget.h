#ifndef TIMEWIDGET_H
#define TIMEWIDGET_H

#include <QLabel>

class TimeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TimeWidget(QWidget *parent = nullptr);
    std::string showTime();
private slots:

private:
     QLabel *time_label;
     QLabel *date_label;

signals:

};

#endif // TIMEWIDGET_H
