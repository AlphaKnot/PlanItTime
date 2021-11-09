#include "uiscreen.h"
#include "ui_uiscreen.h"

UIScreen::UIScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UIScreen)
{
    ui->setupUi(this);
}

UIScreen::~UIScreen()
{
    delete ui;
}

