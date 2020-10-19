#include "totalacres.h"
#include "ui_totalacres.h"

// Default Constructer: setting the total acres of all national
// parks
totalAcres::totalAcres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::totalAcres)
{
    ui->setupUi(this);
}

// destructor
totalAcres::~totalAcres()
{
    delete ui;
}
