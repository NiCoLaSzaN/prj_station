#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "weather.h"
#include <QPixmap>
#include <QDesktopWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);

    // mise en forme de la fenetre de l'application

    QDesktopWidget bureau;
    QRect surface_bureau = bureau.screenGeometry();
    int x = surface_bureau.width()/2 - width()/2;
    int y = surface_bureau.height()/2 - height()/2;
    move(x,y);

    // fond background

    QPixmap pix(":/pic/sky.jpg");
    ui->fond->setPixmap(pix.scaled(867, 867, Qt::KeepAspectRatio));

    // affichage du titre de la fenetre

    this->setWindowTitle("===/ ASTOU / SERGE / NICOLAS /===");

    // affichage heure

    showTime();
    QTimer *timer=new QTimer(this);
    timer->start();
    connect(timer, SIGNAL(timeout()),this,SLOT(showTime()));

    // affichage date

    QDate dateTime;
    QString datetimetext=dateTime.currentDate().toString();
    ui->Date_Time->setText(datetimetext);

    // font label Interieur et Exterieur

    QFont f("Courier",14, QFont::Bold);
    ui->labelINT->setFont(f);
    ui->labelEXT->setFont(f);
    QFont f2("Arial",10,QFont::Bold);
    ui->labelActuel->setFont(f2);
    ui->labelPrevision->setFont(f2);
    ui->Date_Time->setFont(f2);
    ui->Digital_clock->setFont(f2);

    // affichage pictogramme et temperature actuel

    weather w5;
    ui->lineEditPrev1Date->setText(w5.metJourSemaine()[0]+" "+w5.metRecupDateSemaine()[0]);
    ui->lineEditPrev2Date->setText(w5.metJourSemaine()[1]+" "+w5.metRecupDateSemaine()[1]);
    ui->lineEditPrev3Date->setText(w5.metJourSemaine()[2]+" "+w5.metRecupDateSemaine()[2]);
    ui->lineEditPrev4Date->setText(w5.metJourSemaine()[3]+" "+w5.metRecupDateSemaine()[3]);
    ui->lineEditPrev5Date->setText(w5.metJourSemaine()[4]+" "+w5.metRecupDateSemaine()[4]);

    QString meteo;
    meteo = w5.metPictogrammeTmpActuel();
    ui->soleil->setScaledContents(1);
    ui->soleil->setPixmap(w5.metCreationPixmap(meteo));

    ui->lineEditExtHumidity->setText(w5.metExtHumidityC());
    ui->lineEditExtMax->setText(w5.metExtTmpMaxC());
    ui->lineEditExtMin->setText(w5.metExtTmpMinC());
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

    // affichage des datas du capteur

//    ui->lineEditIntTemp->setText(w5.capteur()[0]);
//    ui->lineEditIntHumidity->setText(w5.capteur()[3]);
//    ui->lineEditPression->setText(w5.capteur()[2]);
}
    // methode format d'affichage de l'heure

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

    // affichage temperature exterieur FAHRENHEIT

    weather w3;
        ui->lineEditExtHumidity->setText(w3.metExtHumidityF());
        ui->lineEditExtMax->setText(w3.metExtTmpMaxF());
        ui->lineEditExtMin->setText(w3.metExtTmpMinF());
        ui->lineEditPrev1Temp->setText(w3.metPrevTmpDateF().values()[0]);
        ui->lineEditPrev2Temp->setText(w3.metPrevTmpDateF().values()[1]);
        ui->lineEditPrev3Temp->setText(w3.metPrevTmpDateF().values()[2]);
        ui->lineEditPrev4Temp->setText(w3.metPrevTmpDateF().values()[3]);
        ui->lineEditPrev5Temp->setText(w3.metPrevTmpDateF().values()[4]);

      // affichage jours semaine et date previsions FAHRENHEIT

        ui->lineEditPrev1Date->setText(w3.metJourSemaine()[0]+" "+w3.metRecupDateSemaine()[0]);
        ui->lineEditPrev2Date->setText(w3.metJourSemaine()[1]+" "+w3.metRecupDateSemaine()[1]);
        ui->lineEditPrev3Date->setText(w3.metJourSemaine()[2]+" "+w3.metRecupDateSemaine()[2]);
        ui->lineEditPrev4Date->setText(w3.metJourSemaine()[3]+" "+w3.metRecupDateSemaine()[3]);
        ui->lineEditPrev5Date->setText(w3.metJourSemaine()[4]+" "+w3.metRecupDateSemaine()[4]);

      // affichage des datas du capteur FAHRENHEIT

//        ui->lineEditIntTemp->setText(w3.capteur()[1]);
//        ui->lineEditPression->setText(w3.capteur()[2]);
    }else{

        // affichage des temperatures exterieur CELCIUS

            weather w4;
            ui->lineEditExtHumidity->setText(w4.metExtHumidityC());
            ui->lineEditExtMax->setText(w4.metExtTmpMaxC());
            ui->lineEditExtMin->setText(w4.metExtTmpMinC());
            ui->lineEditPrev1Temp->setText(w4.metPrevTmpDateC().values()[0]);
            ui->lineEditPrev2Temp->setText(w4.metPrevTmpDateC().values()[1]);
            ui->lineEditPrev3Temp->setText(w4.metPrevTmpDateC().values()[2]);
            ui->lineEditPrev4Temp->setText(w4.metPrevTmpDateC().values()[3]);
            ui->lineEditPrev5Temp->setText(w4.metPrevTmpDateC().values()[4]);

            // affichage jours semaine et date previsions CELCIUS

            ui->lineEditPrev1Date->setText(w4.metJourSemaine()[0]+" "+w4.metRecupDateSemaine()[0]);
            ui->lineEditPrev2Date->setText(w4.metJourSemaine()[1]+" "+w4.metRecupDateSemaine()[1]);
            ui->lineEditPrev3Date->setText(w4.metJourSemaine()[2]+" "+w4.metRecupDateSemaine()[2]);
            ui->lineEditPrev4Date->setText(w4.metJourSemaine()[3]+" "+w4.metRecupDateSemaine()[3]);
            ui->lineEditPrev5Date->setText(w4.metJourSemaine()[4]+" "+w4.metRecupDateSemaine()[4]);

            // affichage des datas du capteur CELCIUS

//            ui->lineEditIntTemp->setText(w4.capteur()[0]);
//            ui->lineEditIntHumidity->setText(w4.capteur()[3]);
//            ui->lineEditPression->setText(w4.capteur()[2]);
    }

}


