#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtSql>
#include <QTableView>
#include <QSqlTableModel>

#include <QDebug>


void initializeModel(QSqlTableModel *model)
{

    model->setTable("Facilities");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();


}

QTableView *createView(QSqlTableModel *model, const QString &title="")
{
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setWindowTitle(title);
    return view;

}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("localData");
    db.open();



    QSqlTableModel model;

    initializeModel(&model);

    QTableView *view1 = createView(&model, QObject::tr("Table Model (View 1)"));

    view1->show();

    return app.exec();

}
