#include "totalvisitors.h"
#include "ui_totalvisitors.h"

// Default Constructer: sets the total number of visitors
totalVisitors::totalVisitors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::totalVisitors)
{
    ui->setupUi(this);
}

totalVisitors::~totalVisitors()
{
    delete ui;
}
