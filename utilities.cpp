
#include "mainwindow.h"
#include <QSqlError>
#include <QMessageBox>
#include <QSqlDatabase>



void MainWindow::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}
