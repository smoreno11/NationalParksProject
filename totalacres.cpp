#include "totalacres.h"
#include "ui_totalacres.h"

totalAcres::totalAcres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::totalAcres)
{
    ui->setupUi(this);
}

totalAcres::~totalAcres()
{
    delete ui;
}
