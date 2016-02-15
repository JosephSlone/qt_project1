#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtSql>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlDatabase>

#include <QDebug>

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

void initializeModel(QSqlTableModel *model)
{
    model->setTable("Facilities");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    qDebug() << model->tableName();
    qDebug() << model->database().lastError().databaseText();
}

QTableView *createView(QSqlTableModel *model, const QString &title="")
{
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setWindowTitle(title);
    return view;

}

boolean openConnection()
{
    db.setDatabaseName("localData");
    db.open();

    if (db.isValid())
        return true;
    else
        return false;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QSqlTableModel model;


    if (!openConnection())
        return 1;

    initializeModel(&model);

    QTableView *view1 = createView(&model, QObject::tr("Table Model (View 1)"));

    view1->show();

    return app.exec();

}
