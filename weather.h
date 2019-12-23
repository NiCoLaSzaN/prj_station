#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>
#include <QString>
#include <QTimer>
#include <QDateTime>
#include <QtAlgorithms>
#include <QList>
#include <QBoxLayout>
#include <QLabel>

#include <stdio.h>
#include <iostream>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

class weather : public QObject
{
private :
    QString ExtHumidityC;
    QString ExtTmpMaxC;
    QString ExtTmpMinC;
    QMap<QString,QString>PrevDateC;

    QString ExtHumidityF;
    QString ExtTmpMaxF;
    QString ExtTmpMinF;
    QMap<QString,QString>PrevDateF;

    QList<QString>dataCapteur;

    QString pictoActuel;
    QPixmap pixMap;

    QList<QString>stringPrevision;

    QList<QString>RecupDateSemaine;
    QList<QString>listSemaine;

    QString AffDate;

public:
    weather();

    QString metPictogrammeTmpActuel();
    QPixmap metCreationPixmap(QString);
    QList<QString>metPictogrammeTmpPrevision();
    QPixmap metPixMapPrev(QString);

    QString metExtHumidityC();
    QString metExtTmpMaxC();
    QString metExtTmpMinC();
    QMap<QString,QString> metPrevTmpDateC();

    QString metExtHumidityF();
    QString metExtTmpMaxF();
    QString metExtTmpMinF();
    QMap<QString,QString>metPrevTmpDateF();

    QList<QString>metRecupDateSemaine();
    QList<QString>metJourSemaine();

    QString metAffichageDate();

//    QList<QString>capteur();

};

#endif // WEATHER_H
