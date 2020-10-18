#ifndef PARKSDISPLAY_H
#define PARKSDISPLAY_H

#include <QDialog>
#include <QDebug>
#include <QTableWidget>
#include <QSqlQuery>
#include <QSqlError>
#include "customer.h"
#include "QSqlTableModel"

namespace Ui {
class ParksDisplay;
}

class ParksDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit ParksDisplay(QWidget *parent = nullptr);
    ~ParksDisplay();

private slots:
    void on_nameButton_clicked();

    void on_resetButton_clicked();

    void on_parkNameButton_clicked();

private:
    Ui::ParksDisplay *ui;
};

#endif // PARKSDISPLAY_H
