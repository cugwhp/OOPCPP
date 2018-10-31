/********************************************************************************
** Form generated from reading UI file 'dialogdispopt.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDISPOPT_H
#define UI_DIALOGDISPOPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogDispOpt
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_Red;
    QComboBox *cmbox_Red;
    QComboBox *cmbox_Grn;
    QLabel *label_Grn;
    QLabel *label_Blu;
    QLabel *label_DispType;
    QComboBox *cmbox_Blu;
    QComboBox *cmbox_DispType;

    void setupUi(QDialog *DialogDispOpt)
    {
        if (DialogDispOpt->objectName().isEmpty())
            DialogDispOpt->setObjectName(QStringLiteral("DialogDispOpt"));
        DialogDispOpt->resize(241, 173);
        buttonBox = new QDialogButtonBox(DialogDispOpt);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 140, 156, 23));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_Red = new QLabel(DialogDispOpt);
        label_Red->setObjectName(QStringLiteral("label_Red"));
        label_Red->setGeometry(QRect(30, 20, 54, 12));
        cmbox_Red = new QComboBox(DialogDispOpt);
        cmbox_Red->setObjectName(QStringLiteral("cmbox_Red"));
        cmbox_Red->setGeometry(QRect(100, 10, 121, 20));
        cmbox_Grn = new QComboBox(DialogDispOpt);
        cmbox_Grn->setObjectName(QStringLiteral("cmbox_Grn"));
        cmbox_Grn->setGeometry(QRect(100, 40, 121, 20));
        label_Grn = new QLabel(DialogDispOpt);
        label_Grn->setObjectName(QStringLiteral("label_Grn"));
        label_Grn->setGeometry(QRect(30, 50, 54, 12));
        label_Blu = new QLabel(DialogDispOpt);
        label_Blu->setObjectName(QStringLiteral("label_Blu"));
        label_Blu->setGeometry(QRect(30, 80, 54, 12));
        label_DispType = new QLabel(DialogDispOpt);
        label_DispType->setObjectName(QStringLiteral("label_DispType"));
        label_DispType->setGeometry(QRect(20, 100, 71, 20));
        cmbox_Blu = new QComboBox(DialogDispOpt);
        cmbox_Blu->setObjectName(QStringLiteral("cmbox_Blu"));
        cmbox_Blu->setGeometry(QRect(100, 70, 121, 20));
        cmbox_DispType = new QComboBox(DialogDispOpt);
        cmbox_DispType->addItem(QString());
        cmbox_DispType->addItem(QString());
        cmbox_DispType->setObjectName(QStringLiteral("cmbox_DispType"));
        cmbox_DispType->setGeometry(QRect(100, 100, 121, 20));

        retranslateUi(DialogDispOpt);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogDispOpt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogDispOpt, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogDispOpt);
    } // setupUi

    void retranslateUi(QDialog *DialogDispOpt)
    {
        DialogDispOpt->setWindowTitle(QApplication::translate("DialogDispOpt", "Dialog", nullptr));
        label_Red->setText(QApplication::translate("DialogDispOpt", "Red Band", nullptr));
        label_Grn->setText(QApplication::translate("DialogDispOpt", "Green Band", nullptr));
        label_Blu->setText(QApplication::translate("DialogDispOpt", "Blue Band", nullptr));
        label_DispType->setText(QApplication::translate("DialogDispOpt", "Enhance Type", nullptr));
        cmbox_DispType->setItemText(0, QApplication::translate("DialogDispOpt", "Normal", nullptr));
        cmbox_DispType->setItemText(1, QApplication::translate("DialogDispOpt", "Linear", nullptr));

    } // retranslateUi

};

namespace Ui {
    class DialogDispOpt: public Ui_DialogDispOpt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDISPOPT_H
