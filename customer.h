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


    /*!
    * \brief Default Constructor Customer
    */
  Customer();

  /*!
  * \brief Customer constructor
  * \param The customer
  */
  Customer(const Customer &customer);


  Customer(QString parkName, QString state, int visitors, double size);

  Customer(QSqlQuery &query);

  /*!
  * \brief Customer destructor
  * \param
  */
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

  double getAcres() const;


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

  void setVisitors(int newVisitors);

  void setAcres(double newAcres);

  bool save();

private:
  int id;
  QString parkName;
  QString state;
  int visitors;
  double acres;

};

#endif // CUSTOMER_H
