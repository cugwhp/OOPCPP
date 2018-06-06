#ifndef DIALOGDISPOPT_H
#define DIALOGDISPOPT_H

#include <QDialog>

namespace Ui {
class DialogDispOpt;
}

class DialogDispOpt : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDispOpt(QWidget *parent = 0);
    ~DialogDispOpt();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogDispOpt *ui;
};

#endif // DIALOGDISPOPT_H
