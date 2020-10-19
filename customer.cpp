#include "customer.h"


// Customer constructor
Customer::Customer(const Customer &customer // IN - customer object) {
  id = customer.id;
  parkName = customer.parkName;
  state = customer.state;
  visitors = customer.visitors;
  size = customer.size;

}

// Default constructor - srtting all members to empty values
Customer::Customer() {
  id = -1;
  parkName = "";
  state = "";
  visitors = 0;
  size = 0;
}

// Customer info constructor
Customer::Customer(QString parkName, // IN - Parks name 
                   QString state, // IN - state
                   int visitors, // IN - the number of visitors 
                   double size) // IN - the area of the park
    : parkName(parkName), state(state), visitors(visitors), size(size) {
  id = -1;
}

Customer::Customer(QSqlQuery &query) // IN - SQL object
{
  QString interestStr;

  id = query.value(0).toInt();
  parkName = query.value(1).toString();
  state = query.value(2).toString();
  visitors= query.value(3).toInt();
  size=query.value(4).toDouble();
}

// Destructor
Customer::~Customer() {}

// save() - checks if the SQL and the database works and executes perfectly 
// returns true if the query is successfuly set up                
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
                  "SET park_name=?, street_address=?"
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
  query.addBindValue(size);

  // If save parl did not execute
  if (!query.exec()) {
    qDebug() << "Failed to save park: " << query.lastError().text();
    return false;
  }

  // If park info successfully saved into database
  id = query.lastInsertId().toInt();
  return true;
}
//setId() - sets the parks ID                
void Customer::setId(int newId) // IN - setting the new ID
{
    id = newId;
}

//setParkName() - sets the park's name 
void Customer::setParkName(QString newParkName) // IN - setting the park name
                   {
  parkName = newParkName;
}
//setState() - sets the park's ID                   
void Customer::setState(QString newState) // IN - setting the park's state
              {
  state = newState;
}

//setVisitors() - sets the park's number of visitors                        
void Customer::setVisitors(int newVisitors)// IN - setting the park's number of visitors
{
    visitors = newVisitors;
}

 //setSize() - sets the park's area                  
void Customer::setSize(double newSize)// IN - setting the park's area
{
    size = newSize;
}

// getId - returns the id 
int Customer::getId() const { return id; }
                   
// getParkName - returns the park name as an string comaptible with SQL              
QString Customer::getParkName() const { return parkName; }
                   
// getState - returns the state name                        
QString Customer::getState() const { return state; }
                   
// getVisitors - returns the number of the visitors                      
int Customer::getVisitors() const { return visitors; }
                   
// getSize - returns the area of the park                     
double Customer::getSize() const { return size;}

