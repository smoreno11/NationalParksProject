#include "parks.h"

// Deafualt Constructor: initializing parameters
Parks::Parks() {
  parks = "";
  rating = -1;
}

// Destructor
Parks::Parks(const Parks &test) // IN - Park's object
{
  parks = test.parks;
  rating = test.rating;
}

Parks::Parks(QSqlQuery &query) 
{
  parks = query.value(1).toString();
  rating = query.value(2).toInt();
}

// getParks() - returns park objects
QString Parks::getParks() const { return parks; }

// getRating() - returns park's ratings
int Parks::getRating() const { return rating; }

// setParks() - set a park object 
void Parks::setParks(QString newParks) {
  parks = newParks;
}
// setRating - sets the rating of the park
void Parks::setRating(int newRating) // IN - set rating
{ rating = newRating; }

Parks::Parks(QString parks, int rating)
    : parks(parks), rating(rating) {}

// Destructor
Parks::~Parks() {}

// Parks() - Saves Parks in database, and returns 
// true if the data is executed
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

