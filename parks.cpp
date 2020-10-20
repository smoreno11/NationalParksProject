#include "parks.h"

// Constructor
Parks::Parks() {
  parks = "";
  state = "";
  visitors = 0;
  acres = 0;
}

// Destructor
Parks::Parks(const Parks &test) {
  parks = test.parks;
  state = test.state;
  visitors = test.visitors;
  acres = test.acres;
}

Parks::Parks(QSqlQuery &query) {
  parks = query.value(1).toString();
  state = query.value(2).toString();
  visitors = query.value(3).toInt();
  acres = query.value(4).toDouble();
}

QString Parks::getParks() const { return parks; }

QString Parks::getState() const { return state; }

int Parks::getvisitors() const { return visitors; }

double Parks::getAcres() const { return acres; }

void Parks::setParks(QString newParks) {
  parks = newParks;
}

void Parks::setState(QString newState) {
  state = newState;
}

void Parks::setVisitors(int newVisitors) { visitors = newVisitors; }

void Parks::setAcres(double newAcres) { acres = newAcres; }

Parks::Parks(QString parks, QString state, int visitors, double acres)
    : parks(parks), state(state), visitors(visitors), acres(acres) {}

Parks::~Parks() {}

// Save Parks in database
bool Parks::save() {
  QSqlQuery query;

  query.prepare("INSERT INTO parks "
                "(park_name, state, visitor, acres)"
                "VALUES (?, ?, ?, ?)");
  query.addBindValue(parks);
  query.addBindValue(state);
  query.addBindValue(visitors);
  query.addBindValue(acres);

  // If save Parks did not execute
  if (!query.exec()) {
    qDebug() << "Failed to save Parks: " << query.lastError().text();
    return false;
  }

  // Parks successfully saved in database
  return true;
}

