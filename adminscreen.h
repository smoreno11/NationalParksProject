#ifndef ADMINSCREEN_H
#define ADMINSCREEN_H

#include <QDialog>
#include "texteditor.h"

namespace Ui {
class AdminScreen;
}

class AdminScreen : public QDialog
{
    Q_OBJECT

public:
    explicit AdminScreen(QWidget *parent = nullptr);
    ~AdminScreen();

private slots:
    void on_contactInfoEditGo_clicked();
    
    void on_addPark_clicked(int id, QString park_name, QString state, int acres);

private:
    Ui::AdminScreen *ui;
    texteditor* mTexteditor;
};

#endif // ADMINSCREEN_H
