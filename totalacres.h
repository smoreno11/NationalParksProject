#ifndef TOTALACRES_H
#define TOTALACRES_H

#include <QDialog>

namespace Ui {
class totalAcres;
}

class totalAcres : public QDialog
{
    Q_OBJECT

public:
    explicit totalAcres(QWidget *parent = nullptr);
    ~totalAcres();

private:
    Ui::totalAcres *ui;
};

#endif // TOTALACRES_H
