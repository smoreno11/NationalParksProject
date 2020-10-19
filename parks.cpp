#include "parks.h"

// Constructor
Parks::Parks() {
  parks = "";
  rating = -1;
}

// Destructor
Parks::Parks(const Parks &test) {
  parks = test.parks;
  rating = test.rating;
}

Parks::Parks(QSqlQuery &query) {
  parks = query.value(1).toString();
  rating = query.value(2).toInt();
}

QString Parks::getParks() const { return parks; }

int Parks::getRating() const { return rating; }

void Parks::setParks(QString newParks) {
  parks = newParks;
}
void Parks::setRating(int newRating) { rating = newRating; }

Parks::Parks(QString parks, int rating)
    : parks(parks), rating(rating) {}

Parks::~Parks() {}

// Save Parks in database
bool Parks::save() {
  QSqlQuery query;

  query.prepare("INSERT INTO parks "
                "(parks, rating)"
                "VALUES (?, ?)");
  query.addBindValue(parks);
  query.addBindValue(rating);

  // If save Parks did not execute
  if (!query.exec()) {
    qDebug() << "Failed to save Parkss: " << query.lastError().text();
    return false;
  }

  // Parks successfully saved in database
  return true;
}

