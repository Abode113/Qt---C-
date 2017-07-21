#include "tree.h"
/// *****************************************************
///                  initailize Tree        (1)
void Tree::printt(Ui::Dialog ui){
    // ui نطاق الاسماء الذي ستستعمله
    //ui.label->setText("تجربة");
    //ui.label_2->setText("تجربة");
    //ui.label_3->setText("تجربة");
}

//void Tree::tt(Dialog *ui){
//    ui->label->setText();
//}

Tree::Tree()
{
    root = NULL;
    return;
}
/// *****************************************************
/// *****************************************************
///                 destroy Tree               (2)
Tree::~Tree()
{
    ClearTree(root);
    return;
}
void Tree::ClearTree(TreeNode *T)
{
    if(T==NULL) return;
    if(T->left != NULL) ClearTree(T->left);
    if(T->right != NULL) ClearTree(T->right);
    delete T;
    return;
}
/// *****************************************************
/// *****************************************************
///                 IsEmpty             (3)
bool Tree::isEmpty()
{
    return(root==NULL);
}
/// *****************************************************
/// *****************************************************
///             return copy of node         (4)
TreeNode *Tree::clone(TreeNode * T)
{
    TreeNode *clone;

    clone = new TreeNode();
    *clone = *T;
    clone->left = NULL;
    clone->right = NULL;
    return clone;
}
/// *****************************************************
/// *****************************************************
///                 search          (5)
TreeNode *Tree::SearchNode(TreeNode *Node,int Key)
{
    if (Node == NULL) return Node;
    else {
        if (Key < Node->Key)
            SearchNode(Node->left,Key);
        if (Key > Node->Key)
            SearchNode(Node->right,Key);
        else return(clone(Node));
    }
}
TreeNode *Tree::SearchTree(int Key)
{
    TreeNode * temp = root;
    SearchNode(temp,Key);
}
/// *****************************************************
/// *****************************************************
///             insert node         (6)
void Tree::left_to_right(TreeNode  *&p){
    TreeNode *q=p->left;
    p->left=q->right;
    q->right=p;
    p=q;
}
/********************************/
void Tree::right_to_left(TreeNode *&p){
    TreeNode *q=p->right;
    p->right=q->left;
    q->left=p;
    p=q;
}
int Tree::Insert(TreeNode *&temp,TreeNode *newNode)
{
    if(temp == NULL){
            temp = new TreeNode();
            temp = clone(newNode);
    }
        else{
            if( newNode->Key < temp->Key ){
                Insert(temp->left, newNode);
                if(temp->left->iValue < temp->iValue) {
                    left_to_right(temp);
                }
            }
            else{
                Insert(temp->right, newNode);
                if(temp->right->iValue < temp->iValue) {
                    right_to_left(temp);
                }
            }
        }
   return(true);
}

int Tree::Insert_with_ivalue(int Key, float f, int i, char *cA)
{
    TreeNode *newNode;

    newNode = new TreeNode();
    newNode->Key = Key;
    newNode->fValue = f;
    newNode->iValue = i;
    newNode->balance = 0;
    strcpy(newNode->cArray, cA);
    newNode->left = newNode->right = NULL;

    TreeNode *temp = root;
    return(Insert(root,newNode));
}
int Tree::Insert_without_ivalue(int Key, float f, char *cA)
{
    TreeNode *newNode;

    newNode = new TreeNode();
    newNode->Key = Key;
    newNode->fValue = f;
    newNode->iValue = rand() % 1000 + 1 ;
    newNode->balance = 0;
    strcpy(newNode->cArray, cA);
    newNode->left = newNode->right = NULL;

    TreeNode *temp = root;
    return(Insert(root,newNode));
}
/// *****************************************************
/// *****************************************************
///             Deletete node         (7)
void Tree::del(TreeNode *&p, int x){
        if (p == NULL) return;
        if (p->Key == x) del(p);
        else
            if (x < p->Key) del(p->left,x);
        else del(p->right,x);
    }

/********************************/

void Tree::del(TreeNode *&p){
        if (p->left == NULL && p->right == NULL) {
            delete p;
            p = NULL;
            return;
        }
        if (p->left == NULL && p->right != NULL){
            right_to_left(p);
            del(p->left);
            return;
        }
        if (p->left != NULL && p->right == NULL){
            left_to_right(p);
            del(p->right);
            return;
        }
        if (p->left->iValue < p->right->iValue) {
            left_to_right(p);
            del(p->right);
            } else {
                right_to_left(p);
                del(p->left);
            }
        //update(p);
}
void Tree::Delete(int x){
    del(root,x);
}


/// *****************************************************
/// *****************************************************
///             Print               (8)
int Tree::Treehight(TreeNode *T){
    if (T == NULL || (T->left == NULL && T->right == NULL)) return 0;
    T->balance = 1 + max(Treehight(T->left),Treehight(T->right));
    return T->balance;
}
void Tree::TreeHight(){
    Treehight(root);
}
int Tree::max(int a,int b){
    if (a>b)return a;
    else return b;
}

void Tree::PrintOne(TreeNode *T,Ui::Dialog ui)
{
    //std::cout << T->Key << "\t\t" << T->fValue << "\t\t" << T->iValue << "\t\t"
        //<< T->cArray << "\n";
    //ui.label->setText(ui.label->text() + QString::number(T->balance));
    //ui.label_2->setText(ui.label_2->text() + QString::number(T->Key));
    //ui.label_3->setText(ui.label_3->text() + T->cArray);
}
void Tree::PrintAll(TreeNode *T,Ui::Dialog ui)
{
    if(T != NULL)
    {
        PrintOne(T,ui);
        PrintAll(T->left,ui);
        //PrintOne(T);
        PrintAll(T->right,ui);
    }
}
void Tree::drawEllipse(QGraphicsScene *scene,TreeNode *T,double old_center,double center,double y){

    QPen line(Qt::blue);
    line.setWidth(3);
    QBrush brush(Qt::red);
    scene->addEllipse(center*12,y,10,10,line,brush);



    QPen linepen(Qt::black);
    linepen.setWidth(1);

     if (T != root){
         if (((center*12)+7)<((old_center*12)+42)&&(y+16)>(y-18)){
             scene->addLine((old_center*12)+5,y-10,(center*12)+8,y,linepen);
         }else{
             scene->addLine((old_center*12)+8,y-10,(center*12),y+4,linepen);
         }
     }


}
void Tree::draw(QGraphicsScene *scene,TreeNode *T,double old_center,double center,double y){
    if(T != NULL)
    {
        drawEllipse(scene,T,old_center,center,y);
        old_center = center;
        if (T == root){center = -1;old_center = 0;}
        draw(scene,T->left,old_center,center - T->balance,y+18);
        if (T == root){center = 1;old_center = 0;}
        draw(scene,T->right,old_center,center + T->balance,y+18);
    }
}

void Tree::DrawEllipse(QGraphicsScene *scene){
    draw(scene,root,0,0,10);
}





void Tree::drawEllipse1(QGraphicsScene *scene,TreeNode *T,double old_center,double center,double y){

    QPen line(Qt::blue);
    line.setWidth(3);
    QBrush brush(Qt::red);
    QGraphicsTextItem *txt = new QGraphicsTextItem(T->cArray);
    QGraphicsTextItem *txt1 = new QGraphicsTextItem(QString::number(T->Key));
    QGraphicsTextItem *txt2 = new QGraphicsTextItem(QString::number(T->iValue));
    txt->setY(y+10);
    txt->setX(center*120+25);
    txt1->setY(y+30);
    txt1->setX(center*120+38);
    txt2->setY(y+50);
    txt2->setX(center*120+38);
    txt->setDefaultTextColor(Qt::green);
    txt1->setDefaultTextColor(Qt::green);
    txt2->setDefaultTextColor(Qt::green);
    scene->addEllipse(center*120,y,100,100,line,brush);
    scene->addItem(txt);
    scene->addItem(txt1);
    scene->addItem(txt2);


    QPen linepen(Qt::yellow);
    linepen.setWidth(4);

    if (T != root){
        if (((center*120)+7)<((old_center*120)+42)&&(y+16)>(y-18)){
            scene->addLine((old_center*120)+48,y-18,(center*120)+93,y+16,linepen);
        }else{
            scene->addLine((old_center*120)+48,y-18,(center*120)+7,y+16,linepen);
        }
    }

}
void Tree::draw1(QGraphicsScene *scene,TreeNode *T,double old_center,double center,double y){
    if(T != NULL)
    {
        drawEllipse1(scene,T,old_center,center,y);
        old_center = center;
        if (T == root){center = -1;old_center = 0;}
        draw1(scene,T->left,old_center,center - T->balance,y+120);
        if (T == root){center = 1;old_center = 0;}
        draw1(scene,T->right,old_center,center + T->balance,y+120);
    }
}

void Tree::DrawEllipse1(QGraphicsScene *scene){
    draw1(scene,root,0,0,10);
}




void Tree::drawEllipse2(QGraphicsScene *scene,TreeNode *T,double old_center,double center,double y,int k){

    QPen line(Qt::blue);
    line.setWidth(3);
    QBrush brush(Qt::red);
    if (T->Key == k){
        brush.setColor(Qt::yellow);
    }
    QGraphicsTextItem *txt = new QGraphicsTextItem(T->cArray);
    QGraphicsTextItem *txt1 = new QGraphicsTextItem(QString::number(T->Key));
    QGraphicsTextItem *txt2 = new QGraphicsTextItem(QString::number(T->iValue));
    txt->setY(y+10);
    txt->setX(center*120+25);
    txt1->setY(y+30);
    txt1->setX(center*120+38);
    txt2->setY(y+50);
    txt2->setX(center*120+38);
    txt->setDefaultTextColor(Qt::green);
    txt1->setDefaultTextColor(Qt::green);
    txt2->setDefaultTextColor(Qt::green);
    scene->addEllipse(center*120,y,100,100,line,brush);
    scene->addItem(txt);
    scene->addItem(txt1);
    scene->addItem(txt2);


    QPen linepen(Qt::yellow);
    linepen.setWidth(4);

    if (T != root){
        if (((center*120)+7)<((old_center*120)+42)&&(y+16)>(y-18)){
            scene->addLine((old_center*120)+48,y-18,(center*120)+93,y+16,linepen);
        }else{
            scene->addLine((old_center*120)+48,y-18,(center*120)+7,y+16,linepen);
        }
    }

}
void Tree::draw2(QGraphicsScene *scene,TreeNode *T,double old_center,double center,double y,int k){
    if(T != NULL)
    {
        drawEllipse2(scene,T,old_center,center,y, k);
        old_center = center;
        if (T == root){center = -1;old_center = 0;}
        draw2(scene,T->left,old_center,center - T->balance,y+120,k);
        if (T == root){center = 1;old_center = 0;}
        draw2(scene,T->right,old_center,center + T->balance,y+120,k);
    }
}

void Tree::DrawEllipse2(QGraphicsScene *scene,int k){
    draw2(scene,root,0,0,10,k);
}



void Tree::drawEllipse3(QGraphicsScene *scene,TreeNode *T,double old_center,double center,double y,int k){

    QPen line(Qt::blue);
    line.setWidth(2);
    QBrush brush(Qt::red);
    if (T->Key == k){
        brush.setColor(Qt::yellow);
    }
    scene->addEllipse(center*12,y,10,10,line,brush);



    QPen linepen(Qt::black);
    linepen.setWidth(1);

     if (T != root){
         if (((center*12)+7)<((old_center*12)+42)&&(y+16)>(y-18)){
             scene->addLine((old_center*12)+5,y-10,(center*12)+8,y,linepen);
         }else{
             scene->addLine((old_center*12)+8,y-10,(center*12),y+4,linepen);
         }
     }


}
void Tree::draw3(QGraphicsScene *scene,TreeNode *T,double old_center,double center,double y,int k){
    if(T != NULL)
    {
        drawEllipse3(scene,T,old_center,center,y, k);
        old_center = center;
        if (T == root){center = -1;old_center = 0;}
        draw3(scene,T->left,old_center,center - T->balance,y+18, k);
        if (T == root){center = 1;old_center = 0;}
        draw3(scene,T->right,old_center,center + T->balance,y+18, k);
    }
}

void Tree::DrawEllipse3(QGraphicsScene *scene,int k){
    draw3(scene,root,0,0,10,k);
}


void Tree::PrintTree(Ui::Dialog ui)
{
    PrintAll(root,ui);
}
///******************************************************
///******************************************************
///******************************************************
///            split
void Tree::splite(TreeNode *tree, TreeNode *&right_tree,TreeNode *&left_tree,int key )
{
    if(tree==NULL)
        left_tree=right_tree=NULL;
    else if (tree->Key == key){
        left_tree = tree->left;
        right_tree = tree->right;
    }else{

        if(key<tree->Key){
            right_tree = tree;
            splite(tree->left,right_tree->left,left_tree,key);
        }
        else{
            left_tree = tree;
            splite(tree->right,right_tree,left_tree->right,key);
        }
    }
}
void Tree::Split(Tree *the_left,Tree *the_right,int x){
    splite(root,the_left->root,the_right->root,x);
}



void Tree::join(TreeNode *&main,TreeNode *a,TreeNode *b){
    join(main,a);
    join(main,b);
}
void Tree::join(TreeNode *&a,TreeNode *b){
    if (b != NULL){
        TreeNode *c = new(TreeNode);
        c = clone(b);
        Insert(a,c);
        join(a,b->left);
        join(a,b->right);
    }
}
void Tree::Join(Tree *a,Tree *b){
    join(root,a->root,b->root);
}


/// *****************************************************
/// *****************************************************
void Tree::Go_To_View_1(Ui::Dialog ui,QGraphicsScene *scene){
    ui.page->show();
    ui.page_2->hide();
    ui.page_3->hide();
    ui.page_4->hide();
    ui.page_5->hide();
    ui.page_6->hide();
    ui.page_7->hide();

    scene->clear();
    TreeHight();
    DrawEllipse(scene);
}
void Tree::Go_To_View_2(Ui::Dialog ui,QGraphicsScene *scene){
    ui.page->show();
    ui.page_2->hide();
    ui.page_3->hide();
    ui.page_4->hide();
    ui.page_5->hide();
    ui.page_6->hide();
    ui.page_7->hide();

    scene->clear();
    TreeHight();
    DrawEllipse1(scene);
}
void Tree::Go_To_View_3(Ui::Dialog ui,QGraphicsScene *scene,int k){
    ui.page->show();
    ui.page_2->hide();
    ui.page_3->hide();
    ui.page_4->hide();
    ui.page_5->hide();
    ui.page_6->hide();
    ui.page_7->hide();

    scene->clear();
    TreeHight();
    DrawEllipse2(scene,k);
}
void Tree::Go_To_View_4(Ui::Dialog ui,QGraphicsScene *scene,int k){
    ui.page->show();
    ui.page_2->hide();
    ui.page_3->hide();
    ui.page_4->hide();
    ui.page_5->hide();
    ui.page_6->hide();
    ui.page_7->hide();

    scene->clear();
    TreeHight();
    DrawEllipse3(scene,k);
}
