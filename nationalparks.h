#ifndef NATIONALPARKS_H
#define NATIONALPARKS_H


#include <QMessageBox>
#include <QtSql>
#include <iomanip>
#include <ios>
#include <string>

/*!
 * \brief The NationalParks class
 */
class NationalParks
{
public:

    /*!
     * \brief NationalParks Constructor
     */
    NationalParks();
    /*!
     * \brief NationalParks Constuctor
     * \param NationalParks Object
     */
    NationalParks(const NationalParks &NationalParks);

    /*!
     * \brief NationalParks Constructor
     * \param parkName
     * \param parkState
     * \param numVisitors
     * \param size
     */
    NationalParks(QString parkName, QString parkState, int numVisitors,
             double size);

    /*!
     * \brief NationalParks
     * \param query
     */
    NationalParks(QSqlQuery &query);

    /*!
     *\brief National Parks Destructor
     */
    ~NationalParks();

    /*!
     * \brief save
     * \return Nothing
     */
    bool save();

    /*!
     * \brief getId
     * \return
     */
    int getId() const;

    /*!
     * \brief getNationalPark
     * \return
     */
    QString getNationalPark() const;

    private:

    /*!
     * \brief id
     */
    int id;
    /*!
     * \brief parkName
     */
    QString parkName;
    /*!
     * \brief state
     */
    QString state;
    /*!
     * \brief numVisitors
     */
    int numVisitors;
    /*!
     * \brief size
     */
    double size;

};


#endif // NATIONALPARKS_H
