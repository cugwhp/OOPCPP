#include "dialogdispopt.h"
#include "ui_dialogdispopt.h"
#include <QMessageBox>

DialogDispOpt::DialogDispOpt(int bands, int rgb[3], int dispType,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDispOpt)
{
    ui->setupUi(this);

    QStringList     lstBands;
    for (int i=1; i<=bands; i++)
        lstBands << QString::number(i);

    ui->cmbox_Red->addItems(lstBands);
    ui->cmbox_Grn->addItems(lstBands);
    ui->cmbox_Blu->addItems(lstBands);

    ui->cmbox_Red->setCurrentIndex(rgb[0]);
    ui->cmbox_Grn->setCurrentIndex(rgb[1]);
    ui->cmbox_Blu->setCurrentIndex(rgb[2]);
    ui->cmbox_DispType->setCurrentIndex(dispType);
}

DialogDispOpt::~DialogDispOpt()
{
    delete ui;
}

void DialogDispOpt::on_buttonBox_accepted()
{
    r = ui->cmbox_Red->currentIndex();
    g = ui->cmbox_Grn->currentIndex();
    b = ui->cmbox_Blu->currentIndex();
    dispType = ui->cmbox_DispType->currentIndex();
}
