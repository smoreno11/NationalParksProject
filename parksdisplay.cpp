#include "parksdisplay.h"
#include "ui_parksdisplay.h"
#include "totalvisitors.h"
#include "totalacres.h"
#include "QDebug"

ParksDisplay::ParksDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParksDisplay)
{
    ui->setupUi(this);

    updatedVisitor = 0;
    updatedAcres = 0;

    QSqlQuery query;
    query.prepare("SELECT park_name, state, visitor, acres FROM customers");
    // If the customers could not be loaded onto the parks list
    if (!query.exec()) {
    // Error message
    qDebug() << "Failed to query parks: " << query.lastError().text();
    return;
    }

    while (query.next()) {
        QString parkName = query.value(0).toString();
        QString state = query.value(1).toString();
        int visitors = query.value(2).toInt();
//      QString visitors = query.value(2).toString();
        double acres = query.value(3).toDouble();
        //QString acres = query.value(3).toString();
        updatedVisitor += visitors;
        updatedAcres += acres;

}

    ui->updatedVisitorsLineEdit->setText(QString::number(updatedVisitor));
    ui->updatedAcresLineEdit->setText(QString::number(updatedAcres));
    QSqlQueryModel *search = new QSqlTableModel;
    search->setQuery(query);
    ui->tableView->setModel(search);

    originalList();

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

    while (query.next()) {
         QString parkName = query.value(0).toString();
         QString state = query.value(1).toString();
         QString visitors = query.value(2).toString();
         QString acres = query.value(3).toString();

         QSqlQueryModel *search = new QSqlTableModel;
         search->setQuery(query);
         ui->tableView->setModel(search);

    }

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

    while (query.next()) {
        QString parkName = query.value(0).toString();
        QString state = query.value(1).toString();
        QString visitors = query.value(2).toString();
        QString acres = query.value(3).toString();

        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->setModel(search);
    }
}

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

void ParksDisplay::on_parkNameButton_clicked()
{
    QSqlQuery query;
    //SELECT park_name, state, visitor, acres FROM customers
    query.prepare("SELECT park_name, state, visitor, acres FROM customers ORDER BY park_name");
    // If the customers could not be loaded onto the parks list
    if (!query.exec()) {

        qDebug() << "Failed to query parks: " << query.lastError().text();
        return;
     }

    while (query.next()) {

        QString parkName = query.value(0).toString();
        QString state = query.value(1).toString();
        QString visitors = query.value(2).toString();
        QString acres = query.value(3).toString();

        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->setModel(search);
    }
}

void ParksDisplay::on_areaButton_clicked()
{
    QSqlQuery query;
    //SELECT park_name, state, visitor, acres FROM customers
    query.prepare("SELECT park_name, state, visitor, acres FROM customers ORDER BY acres");
    // If the customers could not be loaded onto the parks list
    if (!query.exec()) {

        qDebug() << "Failed to query parks: " << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString parkName = query.value(0).toString();
        QString state = query.value(1).toString();
        QString visitors = query.value(2).toString();
        QString acres = query.value(3).toString();

        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->setModel(search);
    }
}

void ParksDisplay::on_visitorsButton_clicked()
{
    QSqlQuery query;
    //SELECT park_name, state, visitor, acres FROM customers
    query.prepare("SELECT park_name, state, visitor, acres FROM customers ORDER BY visitor");
    // If the customers could not be loaded onto the parks list
    if (!query.exec()) {

        qDebug() << "Failed to query parks: " << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString parkName = query.value(0).toString();
        QString state = query.value(1).toString();
        QString visitors = query.value(2).toString();
        QString acres = query.value(3).toString();

        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->setModel(search);
    }
}

void ParksDisplay::originalList() {

    originalVisitors = 0;
    originalAcres = 0;

    QSqlQuery query;
    query.prepare("SELECT park_name, state, visitor, acres FROM customers WHERE id BETWEEN 1 AND 11");
    // If the customers could not be loaded onto the parks list
    if (!query.exec()) {
      // Error message
      qDebug() << "Failed to query parks: " << query.lastError().text();
      return;
    }
     while (query.next()) {
        QString parkName = query.value(0).toString();
        QString state = query.value(1).toString();
        int visitors = query.value(2).toInt();
        double acres = query.value(3).toDouble();

        originalVisitors += visitors;
        originalAcres += acres;

}

        ui->originalVisitorsLineEdit->setText(QString::number(originalVisitors));
        ui->originalAcresLineEdit->setText(QString::number(originalAcres));

}

