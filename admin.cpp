#include "admin.h"
#include"mainwindow.h"
#include "ui_admin.h"

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("alternate-background-color: #E4E4E4;background-color:white;selection-background-color:#1492E6;selection-color:white;");
}

admin::~admin()
{
    delete ui;
}

void admin::on_livre_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connopen();
    QSqlQuery* qry =new QSqlQuery(conn.mydb);
    qry->prepare("select nomlivre,annee,auteur,ref,nombre,prix from livre");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connclose();
    qDebug()<<(modal->rowCount());
}

void admin::on_addEmpButton_clicked()
{
    save save;
    save.setModal(true);
    save.exec();
}

void admin::on_updateEmpButton_clicked()
{
    Modifier Modifier ;
    Modifier.setModal(true);
    Modifier.exec();
}

void admin::on_deleteEmpButton_clicked()
{
    Supprimer Supprimer;
    Supprimer.setModal(true);
    Supprimer.exec();
}
