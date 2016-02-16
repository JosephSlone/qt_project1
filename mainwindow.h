#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showError(const QSqlError &err);

    void setName(const QString &name);
    QString name() const;

    void setView();


private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;

};

#endif // MAINWINDOW_H
