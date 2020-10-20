#ifndef TOTALVISITORS_H
#define TOTALVISITORS_H

#include <QDialog>

namespace Ui {
class totalVisitors;
}
/*!
 * \brief The totalVisitors class
 *
 * This class will calculate and add up the
 * visitors of each park and then display the total
 * number of visitors using the GUI.
 */
class totalVisitors : public QDialog
{
    Q_OBJECT

public:
    /*!

    * \brief totalVisitors
    * \param parent
    */

     * \brief totalVisitors
     * \param parent
     */

    explicit totalVisitors(QWidget *parent = nullptr);
    ~totalVisitors();

private:
    /*!

    * \brief ui
    *
    * Private member variable to point to
    * the UI of the totalVisitors class.
    */

     * \brief ui
     *
     * Private member variable to point to
     * the UI of the totalVisitors class.
     */

    Ui::totalVisitors *ui;
};

#endif // TOTALVISITORS_H
