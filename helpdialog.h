#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>

namespace Ui {
class helpDialog;
}
/*!
 * \brief The helpDialog class
 */
class helpDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief helpDialog
     * \param parent
     */
    explicit helpDialog(QWidget *parent = nullptr);
    ~helpDialog();

private:
    /*!
     * \brief ui
     */
    Ui::helpDialog *ui;
};

#endif // HELPDIALOG_H
