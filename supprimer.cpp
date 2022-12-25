#include "supprimer.h"
#include "ui_supprimer.h"
#include"mainwindow.h"

Supprimer::Supprimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Supprimer)
{
    ui->setupUi(this);
}

Supprimer::~Supprimer()
{
    delete ui;
}



void Supprimer::on_pushButton_2_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connopen();
    QSqlQuery* qry =new QSqlQuery(conn.mydb);
    qry->prepare("select nomlivre from livre");
    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox->setModel(modal);
    conn.connclose();
    qDebug()<<(modal->rowCount());
}

void Supprimer::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString nom=ui->comboBox->currentText();
    MainWindow conn;
    if(!conn.connopen()){
        qDebug()<<"Impossible d'accéder à notre basedonnee";
        return;
    }
    conn.connopen();
    QSqlQuery impo;
    impo.prepare("delete from livre where nomlivre='"+nom+"'");
    if(impo.exec()){
        conn.connclose();
    }

}
