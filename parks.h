#ifndef PARKS_H
#define PARKS_H

#include <QDialog>
#include <QListWidgetItem>
#include <QtSql>
#include <iomanip>
#include <ios>
#include <qpushbutton.h>
#include <string>

/**
 * @brief A customer Parks
 *
 * This class contains getters and setters than will
 * allow the data to be inserted into the data base.
 */
class Parks {
public:
  // Constructor
  Parks();

  // Destructor
  ~Parks();

  /**
   * Create a Parks from an SQL query result.
   *
   * Usage (untested):
   * @code{.cpp}
   * QSqlQuery query;
   * query.exec("SELECT * FROM parks");
   * Customer testimoncial(query);
   * @endcode
   *
   * @brief Parks::Parks
   * @param query
   */
  Parks(QSqlQuery &query);
  Parks(const Parks &test);
  Parks(QString parks, QString state, int visitors, double acres);

  /**
   * @brief Set the content of the Parks
   * @param newParks the content
   */
  void setParks(QString newParks);
  /**
   * @brief Set the visitors of the Parks
   * @param newvisitors the visitors
   */

  void setState(QString newState);
  /**
   * @brief Set the state of the Parks
   * @param newState the parks
   */


  void setVisitors(int newVisitors);
  /**
   * @brief Get the content of the Parks
   * @return content of the Parks
   */

   void setAcres(double newAcres);
   /**
    * @brief Get the acres of the Parks
    * @return content of the Parks acres
    */

  QString getParks() const;
  /**
   * @brief Get the visitors of the Parks
   * @return visitors of the Parks
   */

  QString getState() const;


  int getvisitors() const;
  /**
   * If the Parks was already in the database, then the Parks will
   * be update. If the Parks isn't in the database, then the Parks
   * will be inserted into the database.
   *
   * @brief Saves the Parks to the database
   * @return if the Parks was successfully saved in the database
   *
   */

  double getAcres() const;

  bool save();

private:
  QString parks; // The Parks text
  QString state;
  int visitors;  //
  double acres;
};


#endif // PARKS_H
