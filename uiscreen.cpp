#include "uiscreen.h"
#include "ui_uiscreen.h"

/**
 * @brief UIScreen::UIScreen this represents the ui screen
 * @param parent
 */
UIScreen::UIScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UIScreen)
{
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::black);

    // getting the widgets
    tw = new TimeWidget(this);
    tw->setPalette(pal);

    sw = new SolarWidget(this);
    sw->setPalette(pal);

    ui->setupUi(this);
    resize(700,480);
    setVisible(true);
    setWindowTitle(tr("PlanitTime"));
    this->setPalette(pal);

}

UIScreen::~UIScreen()
{
    delete ui;
}

