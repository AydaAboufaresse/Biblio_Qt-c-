#include "modifier.h"
#include "ui_modifier.h"
#include"mainwindow.h"

Modifier::Modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifier)
{
    ui->setupUi(this);
}

Modifier::~Modifier()
{
    delete ui;
}

void Modifier::on_pushButton_2_clicked()
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

void Modifier::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString nom=ui->comboBox->currentText();
    MainWindow conn;
    if(!conn.connopen()){
        qDebug()<<"Impossible d'accéder à notre basedonnee";
        return;
    }
    conn.connopen();
    QSqlQuery impo;
    impo.prepare("select * from livre where nomlivre='"+nom+"'");
    if(impo.exec()){
        while(impo.next()){
            ui->lineEdit->setText(impo.value(0).toString());
            ui->lineEdit_2->setText(impo.value(1).toString());
            ui->lineEdit_4->setText(impo.value(2).toString());
            ui->lineEdit_6->setText(impo.value(3).toString());
            ui->lineEdit_3->setText(impo.value(6).toString());
            ui->lineEdit_5->setText(impo.value(5).toString());
            ui->lineEdit_7->setText(impo.value(4).toString());
        }
        conn.connclose();
    }
}

void Modifier::on_pushButton_clicked()
{
    MainWindow conn;
    QString id,nom,auteur,nombre,prix,refer,annee;
    id=ui->lineEdit->text();
    nom=ui->lineEdit_2->text();
    auteur=ui->lineEdit_4->text();
    nombre=ui->lineEdit_6->text();
    prix=ui->lineEdit_7->text();
    refer=ui->lineEdit_5->text();
    annee=ui->lineEdit_3->text();
    if(!conn.connopen()){
        qDebug()<<"Impossible d'accéder à notre basedonnee";
        return;
    }
    conn.connopen();
    QSqlQuery impo;
    impo.prepare("update livre set nomlivre='"+nom+"',auteur='"+auteur+"',nombre='"+nombre+"',prix='"+prix+"',ref='"+refer+"',annee='"+annee+"' where idlivre='"+id+"' ");
    if(impo.exec()){
        this->hide();
        conn.connclose();
    }else {
        QMessageBox::critical(this,tr("Error"),impo.lastError().text());
    }
}
