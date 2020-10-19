#include "parksdisplay.h"
#include "ui_parksdisplay.h"
#include "totalvisitors.h"
#include "totalacres.h"

ParksDisplay::ParksDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParksDisplay)
{
    ui->setupUi(this);



        QSqlQuery query;
        query.prepare("SELECT park_name, state, visitor, acres FROM customers");
        // If the customers could not be loaded onto the parks list
        if (!query.exec()) {
          // Error message
          qDebug() << "Failed to query parks: " << query.lastError().text();
          return;
        }

            QString parkName = query.value(0).toString();
            QString state = query.value(1).toString();
            QString visitors = query.value(2).toString();
            QString acres = query.value(3).toString();

            QSqlQueryModel *search = new QSqlTableModel;
            search->setQuery(query);
            ui->tableView->setModel(search);

}

ParksDisplay::~ParksDisplay()
{
    delete ui;
}

void ParksDisplay::on_nameButton_clicked()
{

    QSqlQuery query;
    //SELECT park_name, state, visitor, acres FROM customers
    query.prepare("SELECT park_name, state, visitor, acres FROM customers ORDER BY state");
    // If the customers could not be loaded onto the parks list
    if (!query.exec()) {
      // Error message
      qDebug() << "Failed to query parks: " << query.lastError().text();
      return;
    }


        QString parkName = query.value(0).toString();
        QString state = query.value(1).toString();
        QString visitors = query.value(2).toString();
        QString acres = query.value(3).toString();

        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->setModel(search);

}

void ParksDisplay::on_resetButton_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT park_name, state, visitor, acres FROM customers");
    // If the customers could not be loaded onto the parks list
    if (!query.exec()) {
      // Error message
      qDebug() << "Failed to query parks: " << query.lastError().text();
      return;
    }

        QString parkName = query.value(0).toString();
        QString state = query.value(1).toString();
        QString visitors = query.value(2).toString();
        QString acres = query.value(3).toString();

        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->setModel(search);
}


void ParksDisplay::on_parkNameButton_clicked()
{
    QSqlQuery query;
    //SELECT park_name, state, visitor, acres FROM customers
    query.prepare("SELECT park_name, state, visitor, acres FROM customers ORDER BY park_name");
    // If the customers could not be loaded onto the parks list
    if (!query.exec()) {
      // Error message
      qDebug() << "Failed to query parks: " << query.lastError().text();
      return;
    }


        QString parkName = query.value(0).toString();
        QString state = query.value(1).toString();
        QString visitors = query.value(2).toString();
        QString acres = query.value(3).toString();

        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->setModel(search);

void ParksDisplay::on_pushButton_clicked()
{
    totalVisitors totalVis;
    totalVis.setModal(true);
    totalVis.exec();

}

void ParksDisplay::on_pushButton_2_clicked()
{
    totalAcres totalAcr;
    totalAcr.setModal(true);
    totalAcr.exec();

}
