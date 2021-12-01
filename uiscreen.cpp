#include "uiscreen.h"
#include "ui_uiscreen.h"


UIScreen::UIScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UIScreen)
{
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::black);

    tw = new TimeWidget(this);
    tw->setPalette(pal);
    sw = new SolarWidget(this);
    sw->setPalette(pal);
    AlarmWidget* aw = new AlarmWidget(this);
    aw->hide();
    ui->setupUi(this);
    resize(700,480);
    setVisible(true);
    setWindowTitle(tr("PlanitTime"));
    this->setPalette(pal);

}

void changeFace(){
    // Work on event handling
}

UIScreen::~UIScreen()
{
    delete ui;
}

