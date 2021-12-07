#include "alarmwidget.h"

AlarmWidget::AlarmWidget(QWidget *parent) : QWidget(parent)
{
    QFontDatabase::addApplicationFont(QDir::currentPath()+"/fonts/ARCADECLASSIC.TTF"); //set your working dir as your actual working dir not build dir

    // Set UI elements for Alarm Set Screen
        QPalette pal = QPalette();
        pal.setColor(QPalette::WindowText,Qt::cyan);

        add_alarm = new QPushButton("Add",this);
        remove_alarm = new QPushButton("Delete",this);
        //add_alarm->setFlat(true);
        //remove_alarm->setFlat(true);
        add_alarm->autoFillBackground();
        remove_alarm->autoFillBackground();
        add_alarm->setFont(QFont("arcadeclassic",20)); // not case sensitive
        remove_alarm->setFont(QFont("arcadeclassic",20));
        remove_alarm->setStyleSheet(" QPushButton{background-color: black ; color: white}");
        add_alarm->setStyleSheet(" QPushButton{background-color: black ; color: white}");

        //remove_alarm->repaint();
       // remove_alarm->setGeometry(QRect(QPoint(this->x(), this->y()), QSize(50, 50)));
        //add_alarm->setGeometry(QRect(QPoint(515, -85), QSize(200, 200)));
        remove_alarm->setPalette(pal);
        add_alarm->setPalette(pal);
        hour_box = new QComboBox();
        hour_box->setStyleSheet("QComboBox { background-color: black; color:white }");
        hour_box->addItem(QString("1"));
        hour_box->addItem(QString("2"));
        hour_box->addItem(QString("3"));
        hour_box->addItem(QString("4"));
        hour_box->addItem(QString("5"));
        hour_box->addItem(QString("6"));
        hour_box->addItem(QString("7"));
        hour_box->addItem(QString("8"));
        hour_box->addItem(QString("9"));
        hour_box->addItem(QString("10"));
        hour_box->addItem(QString("11"));
        hour_box->addItem(QString("12"));
        minute_box = new QComboBox();
        for(int i = 0 ; i!=60; i++){
            minute_box->addItem(QString::fromStdString(std::to_string(i)));
        }
        AM_PM_Box = new QComboBox();
        AM_PM_Box->addItem(QString("AM"));
        AM_PM_Box->addItem(QString("PM"));
        hour_box->setStyleSheet("QComboBox { background-color: black; color:white }");
        hour_box->setFont(QFont("arcadeclassic"));
        minute_box->setStyleSheet("QComboBox { background-color: black; color:white }");
        minute_box->setFont(QFont("arcadeclassic"));
        AM_PM_Box->setStyleSheet("QComboBox { background-color: black; color:white }");
        AM_PM_Box->setFont(QFont("arcadeclassic"));
        alarmList = new QListWidget(parent);

 // set listeners for widgets
        connect(add_alarm, &QPushButton::clicked, this, &AlarmWidget::addButtonClicked);
        connect(remove_alarm, &QPushButton::clicked, this, &AlarmWidget::removeButtonClicked);
        connect(alarmList, &QListWidget::itemClicked, this,&AlarmWidget::itemClicked);
        alarmList->setPalette(pal);
        alarmList->setFont(QFont("arcadeclassic",20));

        alarmList->setStyleSheet("QListWidget {background-color:black} QListWidget::item:text {background-color:black; color: white} QListWidget::item {border-bottom:1px solid white;} QListWidget::item:selected { background-color:white; color:black; }");
        std::string path = "alarmTime.csv";
        std::string* pathptr = &path;
        bool value = checkFile(*pathptr);
        if(value == true){
            readTimeSlots(*pathptr, alarmList );
        }
        QGridLayout* layout = new QGridLayout(this);

        layout->addWidget(remove_alarm,0,1);
        layout->addWidget(add_alarm,0,3);
        layout->addWidget(alarmList,4,2);
        layout->setColumnStretch(2,3);
        layout->setRowStretch(4,4);
        layout->addWidget(hour_box,5,0);
        layout->addWidget(minute_box,5,1);
        layout->addWidget(AM_PM_Box,5,3);

        //layout->setRowStretch(2,);
        resize(700,480);




}

void AlarmWidget::addButtonClicked(){
    int newstdhour;
    std::string minout;
    if(AM_PM_Box->currentText()!=QString("") && minute_box->currentText() !=QString("") && hour_box->currentText()!=QString("")){
        // Not checking for redudant times. X : XX


        if(AM_PM_Box->currentText() == QString("PM")){
        QString newHour = hour_box->currentText();

        newstdhour = newHour.toInt();
        if(newstdhour!=12){
        newstdhour+=12;
        }
        }
        // edge case
        else if(AM_PM_Box->currentText() == QString("AM") && hour_box->currentText() == "12"){
        newstdhour = 0;
        }
        else newstdhour = hour_box->currentText().toInt();
        std::ofstream myfile;
         myfile.open ("alarmTime.csv",std::ios::app);
         int minbox = minute_box->currentText().toInt();
         if(minbox<10){
             minout= "0"+std::to_string(minbox);
         }else{
             minout = minute_box->currentText().toStdString();
         }
         std::string writeout = std::to_string(newstdhour) +"," + minout +"\n";
         myfile << writeout;
         myfile.close();
         std::string fileloca = "alarmTime.csv";

         readTimeSlots(fileloca, alarmList);

    }

}

void AlarmWidget::removeButtonClicked(){
    std::cout << "Deleteing" << std::endl;
    char filename[14] = "alarmTime.csv";
    std::string filenamestdString = "alarmTime.csv";

    int lineNumber = alarmList->currentRow();
    if(lineNumber!=0){
    alarmList->removeItemWidget(alarmList->selectedItems().at(0));
    delete_line(filename, lineNumber-1);
    readTimeSlots(filenamestdString, alarmList);
    }
    if(lineNumber==0){
        //refresh list
        readTimeSlots(filenamestdString, alarmList);
    }

}

void AlarmWidget::itemClicked(){


}
bool AlarmWidget::checkFile (std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

void AlarmWidget::readTimeSlots(std::string& name, QListWidget* alarmList){
// if file exists, read from it
    std::string line;
    std::string fileDir = name.c_str();
    std::ifstream myfile (fileDir);
    // clear before retriving new alarms .
    alarmList->clear();
    QListWidgetItem *temp = new QListWidgetItem("Alarm      Lists");
    temp->setTextAlignment(Qt::AlignCenter);
    alarmList->addItem(temp);

    while(getline(myfile,line)){
        std::string finalString = "";
         std::vector<std::string> parsedcsv;
         boost::split(parsedcsv, line, boost::is_any_of(","));
         for (int i = 0; i < parsedcsv.size(); i++){
                     if(i%2 ==0){
                         int hour = std::stoi( parsedcsv[i] );
                         hour = hour % 24;
                         if(hour == 0){
                             finalString.append("00:");
                         }
                         else{
                             finalString.append(std::to_string(hour)+ ":");
                         }
                     }

<<<<<<< HEAD

                    else{
                         finalString.append(parsedcsv[i]);

                        std::cout<< finalString << std::endl;
=======
                     }else{
                         if(afterNoon)finalString.append(parsedcsv[i] + " PM");
                         else{finalString.append(parsedcsv[i] + " AM");}

>>>>>>> e71d80b (fixing resources)
                         Times.push_back(finalString);
                          QListWidgetItem *temp = new QListWidgetItem((tr(finalString.c_str())));
                          temp->setTextAlignment(Qt::AlignCenter);
                          alarmList->addItem(temp);

                     }

         }

    }

}
void AlarmWidget::delete_line(char* file_name, int n)
{

// open file in read mode or in mode
   std::ifstream is("alarmTime.csv");

   // open file in write mode or out mode
   std::ofstream ofs;
   ofs.open("temp.txt", std::ofstream::out);

   // loop getting single characters
   char c;
   int line_no = 0;
   while (is.get(c))
   {
       // file content not to be deleted
       if (line_no != n)
           ofs << c;
       // if a newline character
       if (c == '\n')
        line_no++;


   }

   // closing output file
   ofs.close();

   // closing input file
   is.close();

   // remove the original file
   remove(file_name);

   // rename the file
   rename("temp.txt", file_name);

}
// helper method to check if CSV database file exists.

std::vector<std::string> AlarmWidget::getTimes(){
    return Times;
}

