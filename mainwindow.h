#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QListView>
#include <QListWidget>
#include <QListWidgetItem>
#include "QSqlTableModel"
#include "parkdisplay.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow
     * \param parent
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /*!
     * \brief on_parkDisplay_clicked
     */
    void on_parkDisplay_clicked();

    /*!
     * \brief on_pushButton_clicked
     */
    void on_pushButton_clicked();

    /*!
     * \brief on_pushButton_2_clicked
     */
    void on_pushButton_2_clicked();

private:
    /*!
     * \brief ui
     */
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
