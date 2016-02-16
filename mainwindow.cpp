#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities.h"

#include <QDebug>
#include <QSqlTableModel>
#include <QtSql>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("localData");
    if (!db.open())
    {
        qDebug() << "Failed to open database";
    }

    qDebug() << db.database();

    QStringList tables = db.tables();
    for (int i = 0; i < tables.count(); ++i){
        qDebug() << tables.at(i);
    }

    qDebug() << db.connectionName();
    qDebug() << db.databaseName();


    // The Data Model
    model = new QSqlTableModel(ui->tableView);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("Facilities");

    if (!model->select()) {
        qDebug() << "Select Model Failed";
        qDebug() << model->lastError().text();
    }

    ui->tableView->setModel(model);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);



}

MainWindow::~MainWindow()
{
    delete ui;
}




