#include "customer.h"


// Customer constructor
Customer::Customer(const Customer &customer) {
  id = customer.id;
  parkName = customer.parkName;
  state = customer.state;
  visitors = customer.visitors;
  acres = customer.acres;

}

// Default constructor
Customer::Customer() {
  id = -1;
  parkName = "";
  state = "";
  visitors = 0;
  acres = 0;
}

// Customer info constructor
Customer::Customer(QString parkName, QString state, int visitors, double acres)
    : parkName(parkName), state(state), visitors(visitors), acres(acres) {
  id = -1;
}

Customer::Customer(QSqlQuery &query) {
  QString interestStr;

  id = query.value(0).toInt();
  parkName = query.value(1).toString();
  state = query.value(2).toString();
  visitors = query.value(3).toInt();
  acres =query.value(4).toDouble();
}

// Destructor
Customer::~Customer() {}

bool Customer::save() {
  QSqlQuery query;

  query.prepare("SELECT id from customers WHERE park_name=?");
  query.addBindValue(parkName);

  // If existing customer park could not be found
  if (!query.exec()) {
    qDebug() << "Failed to search for existing park name: "
             << query.lastError().text();
    return false;
  }

  // If new park name matches another existing park name
  if (query.next() && query.value(0).toInt() != id) {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("A park already exists with that name.");
    msgBox.exec();
    return false;
  }

  // if the park is in the database, we want to update the park not
  // insert it
  if (id != -1) {
    query.prepare("UPDATE customers "
                  "SET park_name=?, state=?"
                  "visitors=?, acres=?"
                  "WHERE id=?");
    query.bindValue(4, id);
  } else {
    query.prepare(
        "INSERT INTO customers "
        "(park_name, state, visitor, acres)"
        "VALUES (?, ?,?,?)");
  }

  query.addBindValue(parkName);
  query.addBindValue(state);
  query.addBindValue(visitors);
  query.addBindValue(acres);

  // If save parl did not execute
  if (!query.exec()) {
    qDebug() << "Failed to save park: " << query.lastError().text();
    return false;
  }

  // If park info successfully saved into database
  id = query.lastInsertId().toInt();
  return true;
}

void Customer::setId(int newId)
{
    id = newId;
}

void Customer::setParkName(QString newParkName) {
  parkName = newParkName;
}
void Customer::setState(QString newState) {
  state = newState;
}

void Customer::setVisitors(int newVisitors)
{
    visitors = newVisitors;
}

void Customer::setAcres(double newAcres)
{
    acres = newAcres;
}

int Customer::getId() const { return id; }
QString Customer::getParkName() const { return parkName; }
QString Customer::getState() const { return state; }
int Customer::getVisitors() const { return visitors; }
double Customer::getAcres() const { return acres;}

