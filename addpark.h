#ifndef ADDPARK_H
#define ADDPARK_H

#include <QDialog>
#include "customer.h"


namespace Ui {
class addPark;
}

class addPark : public QDialog
{
    Q_OBJECT

public:
    explicit addPark(QWidget *parent = nullptr);
    ~addPark();

    // Get if customer was successfully added to parks list
    bool getSuccessful();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addPark *ui;
    Customer tempParks; // Temporary customer holding new customer data
    bool successful; // If customer was successfully added to customer list
};

#endif // ADDPARK_H
