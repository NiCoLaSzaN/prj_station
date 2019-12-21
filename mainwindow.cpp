#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "weather.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    // affichage de la date et de l' heure et titre de la fenetre

    ui->setupUi(this);
    this->setWindowTitle("===/ ASTOU / SERGE / NICOLAS /===");
    showTime();
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
    QDateTime dateTime=QDateTime::currentDateTime();
    QString datetimetext=dateTime.toString();
    ui->Date_Time->setText(datetimetext);

    // font label setText

    QFont f("Courier",14, QFont::Bold);
    ui->labelINT->setFont(f);
    ui->labelEXT->setFont(f);

    // affichage pictogramme et temperature actuel

    weather w5;
    QString meteo;
    meteo = w5.metPictogrammeTmpActuel();
    ui->soleil->setScaledContents(1);
    ui->soleil->setPixmap(w5.metCreationPixmap(meteo));

    ui->lineEditExtHumidity->setText(w5.metExtHumidityC());
    ui->lineEditExtMax->setText(w5.metExtTmpMaxC());
    ui->lineEditExtMin->setText(w5.metExtTmpMinC());
    ui->lineEditPrev1Date->setText(w5.metPrevTmpDateC().keys()[0]);
    ui->lineEditPrev2Date->setText(w5.metPrevTmpDateC().keys()[1]);
    ui->lineEditPrev3Date->setText(w5.metPrevTmpDateC().keys()[2]);
    ui->lineEditPrev4Date->setText(w5.metPrevTmpDateC().keys()[3]);
    ui->lineEditPrev5Date->setText(w5.metPrevTmpDateC().keys()[4]);
    ui->lineEditPrev1Temp->setText(w5.metPrevTmpDateC().values()[0]);
    ui->lineEditPrev2Temp->setText(w5.metPrevTmpDateC().values()[1]);
    ui->lineEditPrev3Temp->setText(w5.metPrevTmpDateC().values()[2]);
    ui->lineEditPrev4Temp->setText(w5.metPrevTmpDateC().values()[3]);
    ui->lineEditPrev5Temp->setText(w5.metPrevTmpDateC().values()[4]);

    // affichage pictogrammes des previsions

    ui->pict1->setScaledContents(1);
    ui->pict1->setPixmap(w5.metCreationPixmap(w5.metPictogrammeTmpPrevision()[0]));
    ui->pict2->setScaledContents(1);
    ui->pict2->setPixmap(w5.metCreationPixmap(w5.metPictogrammeTmpPrevision()[1]));
    ui->pict3->setScaledContents(1);
    ui->pict3->setPixmap(w5.metCreationPixmap(w5.metPictogrammeTmpPrevision()[2]));
    ui->pict4->setScaledContents(1);
    ui->pict4->setPixmap(w5.metCreationPixmap(w5.metPictogrammeTmpPrevision()[3]));
    ui->pict5->setScaledContents(1);
    ui->pict5->setPixmap(w5.metCreationPixmap(w5.metPictogrammeTmpPrevision()[4]));

    // affichage data capteur

//    ui->lineEditIntTemp->setText(w5.capteur()[0]);
//    ui->lineEditIntHumidity->setText(w5.capteur()[3]);
//    ui->lineEditPression->setText(w5.capteur()[2]);
}

    // methode Date Time

void MainWindow::showTime(){
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    if ((time.second() % 2)== 0){
    time_text[3]= ' ';
    time_text[8]= ' ';
}
 ui->Digital_clock->setText(time_text);
}

MainWindow::~MainWindow(){
    delete ui;
}

    // methode de fermeture de la fenetre fichier => quitter

void MainWindow::on_actionQuitter_triggered(){
    this->close();
}

void MainWindow::on_checkBoxF_stateChanged(int arg1)
{
    if(ui->checkBoxF->isChecked()){
    // methode api exterieur FAHRENHEIT
    weather w3;
        ui->lineEditExtHumidity->setText(w3.metExtHumidityF());
        ui->lineEditExtMax->setText(w3.metExtTmpMaxF());
        ui->lineEditExtMin->setText(w3.metExtTmpMinF());
        ui->lineEditPrev1Date->setText(w3.metPrevTmpDateF().keys()[0]);
        ui->lineEditPrev2Date->setText(w3.metPrevTmpDateF().keys()[1]);
        ui->lineEditPrev3Date->setText(w3.metPrevTmpDateF().keys()[2]);
        ui->lineEditPrev4Date->setText(w3.metPrevTmpDateF().keys()[3]);
        ui->lineEditPrev5Date->setText(w3.metPrevTmpDateF().keys()[4]);
        ui->lineEditPrev1Temp->setText(w3.metPrevTmpDateF().values()[0]);
        ui->lineEditPrev2Temp->setText(w3.metPrevTmpDateF().values()[1]);
        ui->lineEditPrev3Temp->setText(w3.metPrevTmpDateF().values()[2]);
        ui->lineEditPrev4Temp->setText(w3.metPrevTmpDateF().values()[3]);
        ui->lineEditPrev5Temp->setText(w3.metPrevTmpDateF().values()[4]);

        // affichage data capteur

 //       ui->lineEditIntTemp->setText(w3.capteur()[1]);
 //       ui->lineEditPression->setText(w3.capteur()[2]);
    }else{

        // methode api exterieur CELCIUS

            weather w4;
            ui->lineEditExtHumidity->setText(w4.metExtHumidityC());
            ui->lineEditExtMax->setText(w4.metExtTmpMaxC());
            ui->lineEditExtMin->setText(w4.metExtTmpMinC());
            ui->lineEditPrev1Date->setText(w4.metPrevTmpDateC().keys()[0]);
            ui->lineEditPrev2Date->setText(w4.metPrevTmpDateC().keys()[1]);
            ui->lineEditPrev3Date->setText(w4.metPrevTmpDateC().keys()[2]);
            ui->lineEditPrev4Date->setText(w4.metPrevTmpDateC().keys()[3]);
            ui->lineEditPrev5Date->setText(w4.metPrevTmpDateC().keys()[4]);
            ui->lineEditPrev1Temp->setText(w4.metPrevTmpDateC().values()[0]);
            ui->lineEditPrev2Temp->setText(w4.metPrevTmpDateC().values()[1]);
            ui->lineEditPrev3Temp->setText(w4.metPrevTmpDateC().values()[2]);
            ui->lineEditPrev4Temp->setText(w4.metPrevTmpDateC().values()[3]);
            ui->lineEditPrev5Temp->setText(w4.metPrevTmpDateC().values()[4]);

            // affichage data capteur

//            ui->lineEditIntTemp->setText(w4.capteur()[0]);
//            ui->lineEditIntHumidity->setText(w4.capteur()[3]);
//            ui->lineEditPression->setText(w4.capteur()[2]);
    }

}


