#include "save.h"
#include "ui_save.h"
#include"mainwindow.h"
#include"admin.h"
#include<QMessageBox>

save::save(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::save)
{
    ui->setupUi(this);
}

save::~save()
{
    delete ui;
}

void save::on_pushButton_clicked()
{
    MainWindow conn;
    QString nom,auteur,nombre,prix,refer,annee;
    nom=ui->lineEdit->text();
    auteur=ui->lineEdit_2->text();
    nombre=ui->lineEdit_4->text();
    prix=ui->lineEdit_6->text();
    refer=ui->lineEdit_3->text();
    annee=ui->lineEdit_5->text();
    if(!conn.connopen()){
        qDebug()<<"Impossible d'accéder à notre basedonnee";
        return;
    }
    conn.connopen();
    QSqlQuery impo;
    impo.prepare("insert into livre (nomlivre,auteur,nombre,prix,ref,annee) values ('"+nom+"','"+auteur+"','"+nombre+"','"+prix+"','"+refer+"','"+annee+"')");
    if(impo.exec()){
        this->hide();
        conn.connclose();
    }
}
