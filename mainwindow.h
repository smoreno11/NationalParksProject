#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QListView>
#include <QListWidget>
#include <QListWidgetItem>
#include "parkdisplay.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    
    // Default Constructer: initializing the parameters
    // parameters: *parnet - QWidget
    MainWindow(QWidget *parent = nullptr);
    
    // Destructor
    ~MainWindow();

private slots:
    void on_parkDisplay_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
