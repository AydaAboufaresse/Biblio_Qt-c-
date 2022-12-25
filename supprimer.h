#ifndef SUPPRIMER_H
#define SUPPRIMER_H

#include <QDialog>

namespace Ui {
class Supprimer;
}

class Supprimer : public QDialog
{
    Q_OBJECT

public:
    explicit Supprimer(QWidget *parent = nullptr);
    ~Supprimer();

private slots:


    void on_pushButton_2_clicked();


    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::Supprimer *ui;
};

#endif // SUPPRIMER_H
