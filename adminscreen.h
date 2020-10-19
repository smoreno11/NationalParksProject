#ifndef ADMINSCREEN_H
#define ADMINSCREEN_H

#include <QDialog>

namespace Ui {
class AdminScreen;
}
/*!
 * \brief The AdminScreen class
 */
class AdminScreen : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief AdminScreen
     * \param parent
     */
    explicit AdminScreen(QWidget *parent = nullptr);
    /*!
     *\brief Descructor
     */
    ~AdminScreen();

private:
    /*!
     * \brief ui
     */
    Ui::AdminScreen *ui;
};

#endif // ADMINSCREEN_H
