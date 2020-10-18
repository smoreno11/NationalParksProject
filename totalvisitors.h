#ifndef TOTALVISITORS_H
#define TOTALVISITORS_H

#include <QDialog>

namespace Ui {
class totalVisitors;
}

class totalVisitors : public QDialog
{
    Q_OBJECT

public:
    explicit totalVisitors(QWidget *parent = nullptr);
    ~totalVisitors();

private:
    Ui::totalVisitors *ui;
};

#endif // TOTALVISITORS_H
