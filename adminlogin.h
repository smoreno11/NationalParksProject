#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "customer.h"

namespace Ui {
class AdminLogin;
}

/*!
 * \brief The AdminLogin class
 *
 * This class will allow the moderator to
 * log in to the admin version of the program which allows
 * for them to add new parks and alter the code.
 */
class AdminLogin : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief AdminLogin
     * \param parent
     */
    explicit AdminLogin(QWidget *parent = nullptr);
    ~AdminLogin();

private slots:
    /*!
     * \brief on_loginButton_clicked
     *
     * This member function will perform an action
     * when the login button is clicked.
     */
    void on_loginButton_clicked();



private:
    /*!
     * \brief ui
     *
     * Private member pointer variable used to
     * point to the UI of adminLogin.h
     */
    Ui::AdminLogin *ui;
};

#endif // ADMINLOGIN_H
