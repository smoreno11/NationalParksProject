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
    /*!
    * \brief totalVisitors
    * \param parent
    */
    explicit totalVisitors(QWidget *parent = nullptr);
    ~totalVisitors();

private:
    /*!
    * \brief ui
    *
    * Private member variable to point to
    * the UI of the totalVisitors class.
    */
    Ui::totalVisitors *ui;
};

#endif // TOTALVISITORS_H
