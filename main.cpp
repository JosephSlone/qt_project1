#include "mainwindow.h"
#include <QApplication>

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlError>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QString name;
    QSqlError errorId;


    // qDebug can accept piped strings

    qDebug() << "Starting Program";

    // Connect to an ODBC database named "localData"
    // I created this in (localdb)/LocalInstance and created a
    // 32bit ODBC connection for it.

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("localData");
    db.open();  // Yes, we have to open it.

    QSqlQueryModel myQuery;   // A simple query model.

    // Run the query
    // This one should fail, we don't need dbo_

    myQuery.setQuery("SELECT * FROM dbo_Facilities");


    // Get an error object and check for an error.
    // You should be able to test for an error with errorId.isValid()
    // and then do something about it.

    errorId = myQuery.lastError();
    qDebug() << errorId.databaseText();

    // This one should work.

    myQuery.setQuery("SELECT * FROM Facilities");
    errorId = myQuery.lastError();
    qDebug() << errorId.databaseText();


    // Walk through the results and do some simple processing.

    for (int i = 0; i < myQuery.rowCount(); ++i) {
        name = myQuery.record(i).value("Name").toString();
        qDebug() << name;
        w.setName(name);
    }


    w.show();  // Show the window??

    return a.exec();
}
