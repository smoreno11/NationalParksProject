#include "addpark.h"
#include "ui_addpark.h"

addPark::addPark(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPark)
{
    ui->setupUi(this);
    successful = false;
}

addPark::~addPark()
{
    delete ui;
}

void addPark::on_pushButton_clicked()
{
    tempParks.setParkName(ui->parkNameLineEdit->text());
    tempParks.setState(ui->stateLineEdit->text());
    tempParks.setVisitors(ui->vistorsLineEdit->text().toInt());
    tempParks.setAcres(ui->acresLineEdit->text().toDouble());
    tempParks.save();
    successful = true;
    close();
}

void addPark::on_pushButton_2_clicked()
{
    this->hide();
}
