#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QMessageBox>
#include <QtSql>
#include <iomanip>
#include <ios>
#include <string>

/*!
 * \brief Class for individual customer
 */
class Customer {

public:

  // Default constructor
    /*!
   * \brief Default Constructor Customer
   */
  Customer();

  /*!
   * \brief Customer constructor
   * \param The customer
   */
  Customer(const Customer &customer);

  // Customer info constructor
  Customer(QString parkName, QString state, int visitors, double size);

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
  void setId(int newId);

  /**
   * @brief Set the park name
   * @param newParkName
   */
  void setParkName(QString newParkName);

  /**
   * @brief Set the state
   * @param newState
   */
  void setState(QString newState);

  bool save();

private:
  int id;
  QString parkName;
  QString state;
  int visitors;
  double size;

};

#endif // CUSTOMER_H
