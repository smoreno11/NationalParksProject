#include "dummy.h"
#include "parkdisplay.h"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlError"
#include "QSqlTableModel"
#include "ui_dummy.h"

dummy::dummy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dummy)
{
    ui->setupUi(this);

    int accum = 0;

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
//            QString visitors = query.value(2).toString();
        double acres = query.value(3).toDouble();
        //QString acres = query.value(3).toString();
//            acres += acres;
        accum += visitors;

}
        qDebug() << "This is the total" << accum;
        ui->lineEdit->setText(QString::number(accum));
        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->setModel(search);

}

dummy::~dummy()
{
    delete ui;
}
