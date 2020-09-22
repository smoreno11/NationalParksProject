#include "databasesetup.h"
#include "nationalparks.h"


// Set up database for parks info
void setupDB() {
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("storage.db");

  // If database is not accessible
  if (!db.open()) {
    qDebug() << "Can't Connect to DB!";
    return;
  }

  QSqlQuery query;

  // Check to see if the parks table already exists
  query.prepare(
      "SELECT name FROM sqlite_master WHERE type='table' AND name='customers'");
  if (!query.exec()) {
    qDebug() << "Failed to check if parks table exists: "
             << query.lastError().text();
    return;
  }

  // If we get a result then we know the parks table exists
  if (query.next()) {
    qDebug() << "Database already setup";
    return;
  }

  query.prepare(
      "CREATE TABLE customers ("
      "  id INTEGER PRIMARY KEY AUTOINCREMENT,"
      "  park_name TEXT NOT NULL UNIQUE,"
      "  state TEXT NOT NULL,"
      "  visitor INTEGER NOT NULL DEFAULT 0,"
      "  acres INTEGER NOT NULL DEFAULT 0"
      ")");

  // If the customer table could not be generated
  if (!query.exec()) {
    qDebug() << "Failed to create parks table: "
             << query.lastError().text();
    return;
  }

  for (int i = 0; i < SEED_CUSTOMER_COUNT; i++) {
    Customer temp = SEED_CUSTOMERS[i];

    temp.save();
  }


  qDebug() << "Set up database";
}

