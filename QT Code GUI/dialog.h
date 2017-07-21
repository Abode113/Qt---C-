#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    int x=0;
    int y=0;
    ~Dialog();

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_17_clicked();

    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();

    void on_pushButton_20_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();

    void on_radioButton_clicked();
    void on_radioButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();


private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsEllipseItem *circle;

protected:
    //void paintEvent(QPaintEvent *e);
};

struct TreeNode
{
    int      Key;
    float    fValue;
    int      iValue;
    char     cArray[7];
    int balance;
    TreeNode *left;
    TreeNode *right;
};

#endif // DIALOG_H
