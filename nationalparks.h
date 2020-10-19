#ifndef NATIONALPARKS_H
#define NATIONALPARKS_H


#include <QMessageBox>
#include <QtSql>
#include <iomanip>
#include <ios>
#include <string>

class NationalParks
{
public:

    // NationalParks constructor
    NationalParks();
    NationalParks(const NationalParks &NationalParks);

    // NationalParks info constructor
    NationalParks(QString parkName, QString parkState, int numVisitors,
             double size);

    NationalParks(QSqlQuery &query);


    ~NationalParks();

    bool save();

    int getId() const;

    QString getNationalPark() const;

    private:


    int id;
    QString parkName;
    QString state;
    int numVisitors;
    double size;

};


#endif // NATIONALPARKS_H
