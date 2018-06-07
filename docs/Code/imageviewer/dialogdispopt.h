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
    explicit DialogDispOpt(int bands, int rgb[3], int dispType=0, QWidget *parent = 0);
    ~DialogDispOpt();

    int     r, g, b;
    int     dispType;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogDispOpt *ui;
};

#endif // DIALOGDISPOPT_H
