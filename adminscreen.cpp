#include "adminscreen.h"
#include "ui_adminscreen.h"
#include "texteditor.h"
#include "databasesetup.h"
#include <iostream>

AdminScreen::AdminScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminScreen)
{
    ui->setupUi(this);
}

AdminScreen::~AdminScreen()
{
    delete ui;
}

void AdminScreen::on_contactInfoEditGo_clicked()
{
    mTexteditor = new texteditor(this);

    mTexteditor->show();
}

void AdminScreen::on_addPark_clicked(int id, QString park_name, QString state, int acres)
{
    {
        QSqlQuery query2;

        query2.prepare("INSERT INTO customers (id, park_name, state, visitor, acres) VALUES (?,?,?,?,?);");

        QTextStream in(stdin);

        std::cin >> id;
        in >> park_name;
        in >> state;
        std::cin >> acres;

        query2.addBindValue(id);
        query2.addBindValue(park_name);
        query2.addBindValue(state);
        query2.addBindValue(acres);
    }
}
