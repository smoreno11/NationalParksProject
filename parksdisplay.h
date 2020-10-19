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

class ParksDisplay : public QDialog
{
    Q_OBJECT

public:
        /****************************************************************
		 * ParksDisplay ();
		 *   Constructor; initalizes the paratmersx
		 *   Parameters: parent (QWidget) IN - input file name
		 *   Return: none
		 ***************************************************************/
    explicit ParksDisplay(QWidget *parent = nullptr);
    
        /****************************************************************
		 * ~ParksDisplay ();
		 *   Destructor; 
		 *   Parameters: none
		 *   Return: none
		 ***************************************************************/
    ~ParksDisplay();

private slots:
    /****************************************************************
     * on_nameButton_clicked ();
     *   member; sorts the parks by the state
     ***************************************************************/
    void on_nameButton_clicked();
    
    /****************************************************************
     * on_resetButton_clicked ();
     *   member; resets the table to the first organization
     ***************************************************************/
    void on_resetButton_clicked();

    /****************************************************************
     * on_SortByArea_clicked ();
     *   member; sorts the parks by area
     ***************************************************************/
    void on_SortByArea_clicked();
    
     /****************************************************************
     * on_SortByV_clicked ();
     *   member; sorts the parks by the number of visitors
     ***************************************************************/
    void on_SortByV_clicked();
    
     /****************************************************************
     * on_parkNameButton_clicked ();
     *   member; sorts by the name of the parks
     ***************************************************************/
    void on_parkNameButton_clicked();

    /****************************************************************
     * on_pushButton_clicked ();
     *   member; displays the total number of visitors
     ***************************************************************/
    void on_pushButton_clicked();

    /****************************************************************
     * on_pushButton_2_clicked ();
     *   member; displays the total acres of the parks
     ***************************************************************/
    void on_pushButton_2_clicked();


private:
    Ui::ParksDisplay *ui;
};

#endif // PARKSDISPLAY_H
