#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QMessageBox>
#include <QtSql>
#include <iomanip>
#include <ios>
#include <string>

/**
 * @brief Class for individual customer
 */
class Customer {
public:


  // Default constructor
  Customer();

  // Customer constructor
  Customer(const Customer &customer); // IN  - customer object

  // Customer info constructor
  Customer(QString parkName,  // IN - park's name 
           QString state,  // IN - park's state 
           int visitors, // IN - park's number of visitors 
           double size); // IN - park's area 

  Customer(QSqlQuery &query);

  // Destructor
  ~Customer();

  /**
   * @brief Get the ID
   *
   * @return ID
   */
  int getId() const;

  /**
   * @brief Get the park name
   *
   * @return Park name
   */
  QString getParkName() const;

  /**
   * @brief Get the state
   *
   * @return state
   */
  QString getState() const;

  int getVisitors() const;

  double getSize() const;

  void setVisitors(int newVisitors);

  void setSize(double newSize);

  /**
   * @brief Set the id of the customer
   * @param newId
   */
  void setId(int newId); // IN - park's ID

  /**
   * @brief Set the park name
   * @param newParkName
   */
  void setParkName(QString newParkName);  // IN - park's name

  /**
   * @brief Set the state
   * @param newState
   */
  void setState(QString newState);
  
  // save() - returns true if the database is succesfully executed
  bool save();

private:
  int id;       // IN - ID of the park
  QString parkName; // IN - park's name
  QString state;    // IN - park's state
  int visitors;     // IN - number of visitors
  double size;      // IN - area of the park

};

#endif // CUSTOMER_H
