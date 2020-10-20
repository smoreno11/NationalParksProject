#ifndef TOTALACRES_H
#define TOTALACRES_H

#include <QDialog>

namespace Ui {
class totalAcres;
}
/*!
 * \brief The totalAcres class
 *
 * This class will calculate the total
 * of the acres in the database and then output
 * it using the GUI of the program.
 */
class totalAcres : public QDialog
{
    Q_OBJECT

public:
    /*!
    * \brief totalAcres
    * \param parent
    */
    explicit totalAcres(QWidget *parent = nullptr);
    ~totalAcres();

private:
    /*!
    * \brief ui
    *
    * Private member variable to point to the UI
    * of the totalAcres class.
    */
    Ui::totalAcres *ui;
};

#endif // TOTALACRES_H
