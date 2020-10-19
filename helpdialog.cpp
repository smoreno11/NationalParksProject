#include "helpdialog.h"
#include "ui_helpdialog.h"

/****************************************************************
 * Default Constructor
 *   This method sets up the help button and helps the costumer 
 *   to find information easier
 *       - returns  nothing  This will output the help dialoge.
 ***************************************************************/
helpDialog::helpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpDialog)
{
    ui->setupUi(this);
}
/****************************************************************
 * Default Destructor
 */
helpDialog::~helpDialog()
{
    delete ui;
}
