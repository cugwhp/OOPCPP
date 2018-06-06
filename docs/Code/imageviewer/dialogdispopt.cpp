#include "dialogdispopt.h"
#include "ui_dialogdispopt.h"

DialogDispOpt::DialogDispOpt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDispOpt)
{
    ui->setupUi(this);
}

DialogDispOpt::~DialogDispOpt()
{
    delete ui;
}

void DialogDispOpt::on_buttonBox_accepted()
{

}
