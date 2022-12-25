#ifndef ADMIN_H
#define ADMIN_H
#include"save.h"
#include"modifier.h"
#include"supprimer.h"
#include <QDialog>
#include <QMainWindow>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_livre_clicked();

    void on_addEmpButton_clicked();

    void on_updateEmpButton_clicked();

    void on_deleteEmpButton_clicked();

private:
    Ui::admin *ui;
};

#endif // ADMIN_H
