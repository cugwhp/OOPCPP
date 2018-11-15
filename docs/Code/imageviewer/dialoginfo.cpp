#include "dialoginfo.h"
#include "ui_dialoginfo.h"
#include "treeitem.h"
#include "treemodel.h"
#include <QFile>

DialogInfo::DialogInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInfo)
{
    ui->setupUi(this);

 //   QFile file("C:\\Qt\\Qt5.10.1\\Examples\\Qt-5.10.1\\widgets\\itemviews\\editabletreemodel\\default.txt");
 //   file.open(QIODevice::ReadOnly);
    QByteArray  qImageInfo;
    qImageInfo += "Statistics";
    qImageInfo += "\tMin: 10";
    TreeModel model(qImageInfo);

 //   file.close();

    ui->treeView->setModel(&model);
    ui->treeView->setWindowTitle(QObject::tr("Image Information"));
    ui->treeView->show();
}

DialogInfo::~DialogInfo()
{
    delete ui;
}
