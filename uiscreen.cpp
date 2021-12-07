#include "uiscreen.h"
#include "ui_uiscreen.h"

UIScreen::UIScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UIScreen)
{
    facevalue = true;
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::black);


    tw = new TimeWidget(this);
    tw->setPalette(pal);
    sw = new SolarWidget(this);
    sw->setPalette(pal);
    aw = new AlarmWidget(this);
    asw = new AsteroidWidget(this);


    std::string current_time = tw->showTime();
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &UIScreen::alarmCheck);
    timer->start(60000);
    ui->setupUi(this);
    resize(700,480);
    setVisible(true);
    setWindowTitle(tr("PlanitTime"));
    aw->hide();
    this->setPalette(pal);

}

// Timer event for checking between two-widgets , compares current time to alarm set times.
void UIScreen::alarmCheck(){
    std::vector<std::string> alarmTimes = aw->getTimes();
    std::string curr_time = tw->showTime();
    for(int i = 0; i<alarmTimes.size(); i++){

        if(alarmTimes.at(i) == curr_time){
            QTimer::singleShot(200, this, &UIScreen::SoundAlarm);
            return;
        }
    }

}

void UIScreen::SoundAlarm(){
    //QMediaPlayer *player = new QMediaPlayer;
    //player->setSource((QUrl::fromLocalFile("alarm.wav")));
    //player->play();
    std::cout<< "Alarm Sound" << std::endl;
}
void UIScreen::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return) {

        if (facevalue== true) {
            sw->hide();
            asw->hide();
            tw->hide();
            aw->show();
            facevalue = false;

        } else {
            sw->show();
            asw->show();
            tw->show();
            aw->hide();;
            facevalue = true;
        }
    }
}
UIScreen::~UIScreen()
{
    delete ui;
}

