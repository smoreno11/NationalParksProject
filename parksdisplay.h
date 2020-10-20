#ifndef PARKSDISPLAY_H
#define PARKSDISPLAY_H

#include <QDialog>
#include <QDebug>
#include <QTableWidget>
#include <QSqlQuery>
#include <QSqlError>
#include "customer.h"
#include "QSqlTableModel"

namespace Ui {
class ParksDisplay;
}
/*!
 * \brief The ParksDisplay class
 *
 * This class contains all of the UI buttons that
 * are linked to display the park database.
 */
class ParksDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit ParksDisplay(QWidget *parent = nullptr);
    ~ParksDisplay();

    void originalList();

private slots:
    void on_nameButton_clicked();

    void on_resetButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_parkNameButton_clicked();

    void on_areaButton_clicked();

    void on_visitorsButton_clicked();

private:
    /*!
    * \brief ui
    *
    * Private member variable to point to
    * the UI of the parksdisplay
    */
    Ui::ParksDisplay *ui;
    int originalVisitors;
    double originalAcres;
    int updatedVisitor;
    double updatedAcres;
};

#endif // PARKSDISPLAY_H
