#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/user/Desktop/controle.db");
    QString name,password;
    name=ui->lineEdit->text();
    password=ui->lineEdit_2->text();
    if(!mydb.open()){
        qDebug()<<"Impossible d'accéder à notre basedonnee";
        return;
    }
    QSqlQuery impo;

    if(impo.exec("select * from login where nom='"+name+"' and pass='"+password+"'")){
        int count=0;
        while (impo.next()) {
            count++;
        }
     if(count==1){
         ui->label_6->setText("Vous etes connecter!!!!");
        this->hide();
        admin admin;
        admin.setModal(true);
        admin.exec();
     }else{
        ui->label_6->setText("Username ou mot de passe incorrect!!!!");
     }}
}
