#include "nationalparks.h"
#include <QDialog>
#include <QString>

// NationalParks constructor
NationalParks::NationalParks(const NationalParks &NationalParks) {
  id = NationalParks.id;
  parkName = NationalParks.parkName;
  state = NationalParks.state;
  numVisitors = NationalParks.numVisitors;
  size = NationalParks.size;
}

// Default constructor
NationalParks::NationalParks() {
  id = -1;
  parkName = "";
  state = "";
  numVisitors = 0;
  size = 0;
}

// NationalParks info constructor
NationalParks::NationalParks(QString parkName, QString state, int numVisitors,
                             double size)
    : parkName(parkName), state(state),
      numVisitors(numVisitors), size(size) {
  id = -1;
}

NationalParks::NationalParks(QSqlQuery &query) {
  QString interestStr;

  id = query.value(0).toInt();
  parkName = query.value(1).toString();
  state = query.value(2).toString();
  numVisitors = query.value(3).toInt();
  size = query.value(4).toDouble();

}

NationalParks::~NationalParks()
{

}


bool NationalParks::save() {
  QSqlQuery query;
                                                                qDebug() << "gets in here";
  query.prepare("SELECT id from parks WHERE park_=?");
  query.addBindValue(parkName);

  // If existing NationalParks business could not be found
  if (!query.exec()) {
    qDebug() << "Failed to search for existing NationalParks  name: "
             << query.lastError().text();
    return false;
  }


  // If new business name matches another existing business name
  if (query.next() && query.value(0).toInt() != id) {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("A park name already exists with that name.");
    msgBox.exec();
    return false;
  }


  query.addBindValue(parkName);
  query.addBindValue(state);
  query.addBindValue(numVisitors);
  query.addBindValue(size);


  // If save NationalParks did not execute
  if (!query.exec()) {
    qDebug() << "Failed to save NationalParks: " << query.lastError().text();
    return false;
  }

  // If NationalParks info successfully saved into database
  id = query.lastInsertId().toInt();
  return true;
}


int NationalParks::getId() const
{
    return id;
}

QString NationalParks::getNationalPark() const { return parkName; }
