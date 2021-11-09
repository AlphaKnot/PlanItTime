#include "uiscreen.h"
#include "ui_uiscreen.h"


UIScreen::UIScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UIScreen)
{
    tw = new TimeWidget(this);
    ui->setupUi(this);
    resize(640,480);
    setVisible(true);
    setWindowTitle(tr("PlanitTime"));

}

UIScreen::~UIScreen()
{
    delete ui;
}

