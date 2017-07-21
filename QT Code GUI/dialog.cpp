#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include "tree.h"

TreeNode *newNode;
Tree    *theTree = new Tree();
Tree    *theTree1 = new Tree();
Tree    *theTree2 = new Tree();


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QPen line(Qt::blue);
    line.setWidth(3);
    QBrush brush(Qt::red);
    scene->addEllipse(10,10,150,150,line,brush);

    QGraphicsTextItem *txt1 = new QGraphicsTextItem("cArray");
    QGraphicsTextItem *txt2 = new QGraphicsTextItem("Key");
    QGraphicsTextItem *txt3 = new QGraphicsTextItem("ivalue");

    txt1->setDefaultTextColor(Qt::green);
    txt2->setDefaultTextColor(Qt::green);
    txt3->setDefaultTextColor(Qt::green);

    txt1->setPos(60,30);
    txt2->setPos(65,70);
    txt3->setPos(60,110);

    scene->addItem(txt1);
    scene->addItem(txt2);
    scene->addItem(txt3);


        ui->page->show();
        ui->page_2->hide();
        ui->page_3->hide();
        ui->page_4->hide();
        ui->page_5->hide();
        ui->page_6->hide();
        ui->page_7->hide();


}



Dialog::~Dialog()
{
    delete ui;
}
////-------------------------------------------------------------------------------
void Dialog::on_pushButton_4_clicked()       //// Delete
{
    //// ------------------------
    ui->page->hide();
    ui->page_2->show();
    ui->page_3->hide();
    ui->page_4->hide();
    ui->page_5->hide();
    ui->page_6->hide();
    ui->page_7->hide();
    //// ------------------------

}
void Dialog::on_pushButton_14_clicked()     //// Delete
{
    if(ui->radioButton_12->isChecked()){
        theTree->Delete(ui->lineEdit_5->text().toInt());
    }
    if(ui->radioButton_13->isChecked()){
        theTree1->Delete(ui->lineEdit_5->text().toInt());
    }
    if(ui->radioButton_14->isChecked()){
        theTree2->Delete(ui->lineEdit_5->text().toInt());
    }
    ui->lineEdit_5->clear();
}

void Dialog::on_pushButton_15_clicked()     //// Go To View 1
{
    if(ui->radioButton_9->isChecked()){
        theTree->Go_To_View_1(*ui,scene);
    }
    if(ui->radioButton_10->isChecked()){
        theTree1->Go_To_View_1(*ui,scene);
    }
    if(ui->radioButton_11->isChecked()){
        theTree2->Go_To_View_1(*ui,scene);
    }
}

void Dialog::on_pushButton_16_clicked()     //// Go To View 2
{
    if(ui->radioButton_9->isChecked()){
        theTree->Go_To_View_2(*ui,scene);
    }
    if(ui->radioButton_10->isChecked()){
        theTree1->Go_To_View_2(*ui,scene);
    }
    if(ui->radioButton_11->isChecked()){
        theTree2->Go_To_View_2(*ui,scene);
    }
}
////-------------------------------------------------------------------------------
void Dialog::on_pushButton_5_clicked()      //// Splite
{
    //// ------------------------
    ui->page->hide();
    ui->page_2->hide();
    ui->page_3->show();
    ui->page_4->hide();
    ui->page_5->hide();
    ui->page_6->hide();
    ui->page_7->hide();
    //// ------------------------
}
void Dialog::on_pushButton_7_clicked()
{
    theTree->Split(theTree1,theTree2,ui->lineEdit_6->text().toInt());
    ui->lineEdit_6->clear();
}

void Dialog::on_pushButton_11_clicked()     //// view 1
{
    if(ui->radioButton_15->isChecked()){
        theTree->Go_To_View_1(*ui,scene);
    }
    if(ui->radioButton_16->isChecked()){
        theTree1->Go_To_View_1(*ui,scene);
    }
    if(ui->radioButton_17->isChecked()){
        theTree2->Go_To_View_1(*ui,scene);
    }
}

void Dialog::on_pushButton_9_clicked()      //// view 2
{
    if(ui->radioButton_15->isChecked()){
        theTree->Go_To_View_2(*ui,scene);
    }
    if(ui->radioButton_16->isChecked()){
        theTree1->Go_To_View_2(*ui,scene);
    }
    if(ui->radioButton_17->isChecked()){
        theTree2->Go_To_View_2(*ui,scene);
    }
}
////-------------------------------------------------------------------------------
void Dialog::on_pushButton_3_clicked()      //// Insert
{
    //// ------------------------
    ui->page->hide();
    ui->page_2->hide();
    ui->page_3->hide();
    ui->page_4->show();
    ui->page_5->hide();
    ui->page_6->hide();
    ui->page_7->hide();
    //// ------------------------


}
void Dialog::on_pushButton_12_clicked()     //// Push
{
    //ui->label_8->setText(ui->lineEdit->text());//// cArray
    //ui->label_9->setText(ui->lineEdit_2->text());
    //ui->label_10->setText((ui->lineEdit_3->text()));
    //ui->label_11->setText((ui->lineEdit_4->text()));
    int n1 = ui->lineEdit_3->text().toInt();
    int n2 = ui->lineEdit_4->text().toInt();
    int n3 = ui->lineEdit_2->text().toInt();
    char n4[7];
    QString a = ui->lineEdit->text();
    QByteArray ba = a.toLatin1();
    strcpy(n4,ba.data());////////////////////

    if (ui->radioButton_3->isChecked()){
        if (ui->radioButton->isChecked()){
            theTree->Insert_without_ivalue(n1,n2,n4);
        }else{
            theTree->Insert_with_ivalue(n1,n2,n3,n4);
        }
    }
    if (ui->radioButton_4->isChecked()){
        if (ui->radioButton->isChecked()){
            theTree1->Insert_without_ivalue(n1,n2,n4);
        }else{
            theTree1->Insert_with_ivalue(n1,n2,n3,n4);
        }
    }
    if (ui->radioButton_5->isChecked()){
        if (ui->radioButton->isChecked()){
            theTree2->Insert_without_ivalue(n1,n2,n4);
        }else{
            theTree2->Insert_with_ivalue(n1,n2,n3,n4);
        }
    }

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();



}
void Dialog::on_pushButton_13_clicked()     //// Go To View 1
{
    if(ui->radioButton_6->isChecked()){
        theTree->Go_To_View_1(*ui,scene);
    }
    if(ui->radioButton_7->isChecked()){
        theTree1->Go_To_View_1(*ui,scene);
    }
    if(ui->radioButton_8->isChecked()){
        theTree2->Go_To_View_1(*ui,scene);
    }
}

void Dialog::on_pushButton_17_clicked()     //// Go To View 2
{
    if(ui->radioButton_6->isChecked()){
        theTree->Go_To_View_2(*ui,scene);
    }
    if(ui->radioButton_7->isChecked()){
        theTree1->Go_To_View_2(*ui,scene);
    }
    if(ui->radioButton_8->isChecked()){
        theTree2->Go_To_View_2(*ui,scene);
    }
}
////-------------------------------------------------------------------------------
void Dialog::on_pushButton_2_clicked()      //// Credit
{
    //scene->clear();

    ui->page->show();
    ui->page_2->hide();
    ui->page_3->hide();
    ui->page_4->hide();
    ui->page_5->hide();
    ui->page_6->hide();
    ui->page_7->hide();

    scene->clear();

    QPen line(Qt::red);
    line.setWidth(3);
    scene->addEllipse(0,0,200,200,line);

    QGraphicsTextItem *txt1 = new QGraphicsTextItem("عبد الرحمن الحوراني");
        QGraphicsTextItem *txt2 = new QGraphicsTextItem("محمد عيد التل");
        QGraphicsTextItem *txt3 = new QGraphicsTextItem("محمد الخياط");
        QGraphicsTextItem *txt4 = new QGraphicsTextItem("وائل حموش");

        txt1->setDefaultTextColor(Qt::green);
        txt2->setDefaultTextColor(Qt::green);
        txt3->setDefaultTextColor(Qt::green);
        txt4->setDefaultTextColor(Qt::green);

        txt1->setPos(35,30);
        txt2->setPos(50,70);
        txt3->setPos(55,100);
        txt4->setPos(55,120);

        scene->addItem(txt1);
        scene->addItem(txt2);
        scene->addItem(txt3);
        scene->addItem(txt4);

}
////-------------------------------------------------------------------------------
void Dialog::on_pushButton_clicked()        //// Join
{
    //// ------------------------
    ui->page->hide();
    ui->page_2->hide();
    ui->page_3->hide();
    ui->page_4->hide();
    ui->page_5->hide();
    ui->page_6->show();
    ui->page_7->hide();
    //// ------------------------
}
void Dialog::on_pushButton_20_clicked()     //// Join
{
    theTree->Join(theTree1,theTree2);
}
void Dialog::on_pushButton_18_clicked()     //// Go To View 1
{
    theTree->Go_To_View_1(*ui,scene);
}

void Dialog::on_pushButton_19_clicked()     //// Go To View 2
{
    theTree->Go_To_View_2(*ui,scene);
}
////-------------------------------------------------------------------------------
void Dialog::on_pushButton_6_clicked()      //// Search
{
    //// ------------------------
    ui->page->hide();
    ui->page_2->hide();
    ui->page_3->hide();
    ui->page_4->hide();
    ui->page_5->show();
    ui->page_6->hide();
    ui->page_7->hide();
    //// ------------------------
}
void Dialog::on_pushButton_8_clicked()
{
    if(ui->radioButton_21->isChecked()){
        theTree->SearchTree(ui->lineEdit_7->text().toInt());
        if(ui->radioButton_18->isChecked()){
            theTree->Go_To_View_3(*ui,scene,ui->lineEdit_7->text().toInt());
        }
        if(ui->radioButton_19->isChecked()){
            theTree->Go_To_View_4(*ui,scene,ui->lineEdit_7->text().toInt());
        }
    }
    if(ui->radioButton_22->isChecked()){
        theTree1->SearchTree(ui->lineEdit_7->text().toInt());
        if(ui->radioButton_18->isChecked()){
            theTree1->Go_To_View_3(*ui,scene,ui->lineEdit_7->text().toInt());
        }
        if(ui->radioButton_19->isChecked()){
            theTree1->Go_To_View_4(*ui,scene,ui->lineEdit_7->text().toInt());
        }
    }
    if(ui->radioButton_23->isChecked()){
        theTree2->SearchTree(ui->lineEdit_7->text().toInt());
        if(ui->radioButton_18->isChecked()){
            theTree2->Go_To_View_3(*ui,scene,ui->lineEdit_7->text().toInt());
        }
        if(ui->radioButton_19->isChecked()){
            theTree2->Go_To_View_4(*ui,scene,ui->lineEdit_7->text().toInt());
        }
    }
    ui->lineEdit_5->clear();
}

////-------------------------------------------------------------------------------
void Dialog::on_radioButton_clicked()
{
    ui->lineEdit_2->setEnabled(false);
    /*
    //static bool chek=false;
    ui->lineEdit_2->setEnabled(false);
    //chek = (chek)?false:true;
    */
}


void Dialog::on_radioButton_2_clicked()
{
    ui->lineEdit_2->setEnabled(true);
    /*
    static bool chek=false;
    //ui->lineEdit_2->setEnabled(chek);
    if(ui->radioButton->isChecked())
    QMessageBox::information(this,"Console","this is information");
    chek = (chek)?false:true;
    */
}




