#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "admin.h"
#include <QMainWindow>
#include <QDialog>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase mydb ;
    void connclose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connopen(){
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/user/Desktop/controle.db");
        if(!mydb.open()){
            qDebug()<<"Impossible d'accéder à notre basedonnee";
            return false;
        }  else{
            qDebug()<<"Connected";
            return true;
        }
    }
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
