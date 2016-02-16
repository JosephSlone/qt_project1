#include "mainwindow.h"
#include "utilities.h"
#include <QApplication>
#include <QtGui>
#include <QtSql>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QStringList>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;


    w.show();

    return app.exec();

}
