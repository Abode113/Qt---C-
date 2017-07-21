#ifndef TREE_H
#define TREE_H
#include"dialog.h"
#include"ui_dialog.h"
class Tree{
private:
    TreeNode *root;

public:
    void printt(Ui::Dialog ui);

    //void tt(Dialog);
    Tree();
    ~Tree();
    bool isEmpty();

    TreeNode *SearchTree(int Key);
    TreeNode *SearchNode(TreeNode *Node,int Key);

    void left_to_right(TreeNode *&p);
    void right_to_left(TreeNode *&p);

    int Insert(TreeNode *&temp,TreeNode *newNode);
    int Insert_with_ivalue(int Key, float f, int i, char *cA);
    int Insert_without_ivalue(int Key, float f, char *cA);

    void del(TreeNode *&p, int x);
    void del(TreeNode *&p);
    void Delete(int x);

    void PrintOne(TreeNode *T,Ui::Dialog ui);
    void PrintTree(Ui::Dialog ui);
    int Treehight(TreeNode *T);
    void TreeHight();
    int max(int a,int b);
    void drawEllipse(QGraphicsScene *ui,TreeNode *T,double old_center,double x,double y);
    void DrawEllipse(QGraphicsScene *scene);
    void draw(QGraphicsScene *scene,TreeNode *T,double old_center,double x,double y);
    void drawEllipse1(QGraphicsScene *ui,TreeNode *T,double old_center,double x,double y);
    void DrawEllipse1(QGraphicsScene *scene);
    void draw1(QGraphicsScene *scene,TreeNode *T,double old_center,double x,double y);

    void drawEllipse2(QGraphicsScene *ui,TreeNode *T,double old_center,double x,double y,int k);
    void DrawEllipse2(QGraphicsScene *scene,int k);
    void draw2(QGraphicsScene *scene,TreeNode *T,double old_center,double x,double y,int k);
    void drawEllipse3(QGraphicsScene *ui,TreeNode *T,double old_center,double x,double y,int k);
    void DrawEllipse3(QGraphicsScene *scene,int k);
    void draw3(QGraphicsScene *scene,TreeNode *T,double old_center,double x,double y,int k);

    void splite(TreeNode *, TreeNode *&,TreeNode *&,int);
    void Split(Tree *,Tree *,int);

    void Go_To_View_1(Ui::Dialog ui,QGraphicsScene *scene);
    void Go_To_View_2(Ui::Dialog ui,QGraphicsScene *scene);
    void Go_To_View_3(Ui::Dialog ui,QGraphicsScene *scene,int k);
    void Go_To_View_4(Ui::Dialog ui,QGraphicsScene *scene,int k);

    void join(TreeNode *&main,TreeNode *a,TreeNode *b);
    void join(TreeNode *&a,TreeNode *b);
    void Join(Tree *a,Tree *b);

private:
    void ClearTree(TreeNode *T);
    TreeNode *clone(TreeNode * T);
    void PrintAll(TreeNode *T,Ui::Dialog ui);
    };

#endif // TREE_H
