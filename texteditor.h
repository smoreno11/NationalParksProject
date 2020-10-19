#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>

namespace Ui {
class texteditor;
}

class texteditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit texteditor(QWidget *parent = nullptr);
    ~texteditor();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::texteditor *ui;
    QString mFileName;
};

#endif // TEXTEDITOR_H
