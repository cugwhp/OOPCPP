#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#ifndef QT_NO_PRINTER
#include <QPrinter>
#endif
#include "RSImage.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool loadFile(const QString &);

private:
    Ui::MainWindow *ui;

private slots:
    void Open();
    void saveAs();
    void print();
    void copy();
    void paste();
    void zoomIn();
    void zoomOut();
    void normalSize();
    void fitToWindow();
    void about();

    void displayOption();
    void imageInformation();

private:
    void updateActions();
    bool saveFile(const QString &fileName);
    void setImage(const QImage &newImage);
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    QImage loadImageFile();
    QImage loadRSImageFile();

    QImage image;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    double scaleFactor;

    CRSImage    m_oRSImage;     //遥感图像数据对象
    int     m_iRedBand, m_iGrnBand, m_iBluBand; //RGB组合
    EDT         m_edtDispType;  //增强显示方式

#ifndef QT_NO_PRINTER
    QPrinter printer;
#endif
};

#endif // MAINWINDOW_H
