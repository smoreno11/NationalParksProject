#ifndef DUMMY_H
#define DUMMY_H

#include <QDialog>

namespace Ui {
class dummy;
}

class dummy : public QDialog
{
    Q_OBJECT

public:
    explicit dummy(QWidget *parent = nullptr);
    ~dummy();

private:
    Ui::dummy *ui;
};

#endif // DUMMY_H
