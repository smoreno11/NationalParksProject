#include "parksdisplay.h"
#include "ui_parksdisplay.h"
#include "totalvisitors.h"
#include "totalacres.h"

/**********************************************************
 * Constructor - ParksDisplay
 * _________________________________________________________
 * This method initializes the parameters
 *_________________________________________________________
 * PRE-CONDITION
 * 		parent
 ************************************************************/
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

// Default Constructor
ParksDisplay::~ParksDisplay()
{
    delete ui;
}

/**********************************************************
 * Functions - on_nameButton_clicked
 * _________________________________________________________
 * This function sorts the parks list alphabetically by state
 ************************************************************/
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

/**********************************************************
 * Functions - on_resetButton_clicked
 * _________________________________________________________
 * This function resets the table to initial organization
 ************************************************************/
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

/**********************************************************
 * Functions - on_parkNameButton_clicked
 * _________________________________________________________
 * This method sorts the park by their name
 ************************************************************/
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

 /**********************************************************
 * Functions - on_pushButton_clicked
 * _________________________________________________________
 * This method displays the total numebr of visitors
 ************************************************************/
void ParksDisplay::on_pushButton_clicked()
{
    totalVisitors totalVis;
    totalVis.setModal(true);
    totalVis.exec();

}
/**********************************************************
 * Functions - on_pushButton_2_clicked
 * _________________________________________________________
 * This method displays the total numebr of acres 
 ************************************************************/
void ParksDisplay::on_pushButton_2_clicked()
{
    totalAcres totalAcr;
    totalAcr.setModal(true);
    totalAcr.exec();

}
    
/**********************************************************
 * Functions - on_SortByV_clicked
 * _________________________________________________________
 * This method sorts the park by their number of visitors
 ************************************************************/
void ParksDisplay::on_SortByV_clicked()
{
    QString noidea;
       noidea.append("SELECT * FROM customers ORDER BY visitor ASC;");
    QSqlQuery query;
    query.prepare(noidea);
    // If the customers could not be loaded onto the parks list
    if (!query.exec()) {
      // Error message
      qDebug() << "Failed to query parks: " << query.lastError().text();
      return;
    }
    QSqlQueryModel *search = new QSqlTableModel;
    search->setQuery(query);
    ui->tableView->setModel(search);
}
    
/**********************************************************
 * Functions - on_SortByArea_clicked
 * _________________________________________________________
 * This method sorts the park by their area
 ************************************************************/
void ParksDisplay:: on_SortByArea_clicked()
{
    QString noidea;
       noidea.append("SELECT * FROM customers ORDER BY acres ASC;");
    QSqlQuery query;
    query.prepare(noidea);
    // If the customers could not be loaded onto the parks list
    if (!query.exec()) {
      // Error message
      qDebug() << "Failed to query parks: " << query.lastError().text();
      return;
    }
    QSqlQueryModel *search = new QSqlTableModel;
    search->setQuery(query);
    ui->tableView->setModel(search);
}
