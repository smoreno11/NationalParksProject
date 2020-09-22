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
 */
class Parks {
public:
  // Constructor
  Parks();

  // Destructor
  ~Parks();

  /**
   * Create a Parks from an SQL query result. Before calling this
   * contructor, you must query for the testimoncial. This will only extract the
   * necessary data for the testimoncial from the query object.
   *
   * Usage (untested):
   * @code{.cpp}
   * QSqlQuery query;
   * query.exec("SELECT * FROM testimoncial");
   * Customer testimoncial(query);
   * @endcode
   *
   * @brief Parks::Parks
   * @param query
   */
  Parks(QSqlQuery &query);
  Parks(const Parks &test);
  Parks(QString parks, int rating);

  /**
   * @brief Set the content of the Parks
   * @param newParks the content
   */
  void setParks(QString newParks);
  /**
   * @brief Set the rating of the Parks
   * @param newRating the rating
   */
  void setRating(int newRating);
  /**
   * @brief Get the content of the Parks
   * @return content of the Parks
   */
  QString getParks() const;
  /**
   * @brief Get the rating of the Parks
   * @return rating of the Parks
   */
  int getRating() const;
  /**
   * If the Parks was already in the database, then the Parks will
   * be update. If the Parks isn't in the database, then the Parks
   * will be inserted into the database.
   *
   * @brief Saves the Parks to the database
   * @return if the Parks was successfully saved in the database
   *
   */
  bool save();

private:
  QString parks; // The Parks text
  int rating;          // Numerical rating of iRobot products
};


#endif // PARKS_H
