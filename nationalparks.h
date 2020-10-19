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

    // Deafualt constructor: Initializing all the parameters
    NationalParks();
    NationalParks(const NationalParks &NationalParks); // IN - NationalParks Object

    // NationalParks info constructor
    NationalParks(QString parkName,  // IN - park's name
                  QString parkState, // IN - park's state
                  int numVisitors,      // IN - park's number of visitors
             double size);          // IN - park's area

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
