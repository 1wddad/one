#ifndef __SLIST_H
#define __SLIST_H
typedef struct  Car1  
{
    int  line;  //线路
    char  start[20];   //起始点
    char  stop[20];    //目的地
    char  current[20];  //当前位置
    float km;     //里程
    char model[20];  //车的型号
    char color[10];  //车的颜色
    float money;    //价格
    float len;   //车长
    float wid;  //车宽
    int speed;  //时速
}Car;

typedef  Car DATA; 
typedef struct node   //linklist
{
    DATA  data;  //结构体类型的数据
    struct node  *next;
}NODE;

typedef int DATA1;
typedef  struct node1
{
    DATA1 data;
    struct node1 *left;   //左孩子
    struct node1 *right;   //右孩子
}BinNODE;


typedef struct node2   //sclinklist
{
    DATA data;
    struct node2 *next;   //指针域next
}SCNODE;

int linklist_create(NODE **head,DATA data);  //单链表创造
int linklist_addHead(NODE **head,DATA data);   //头插
int linklist_addTail(NODE **head,DATA data);  //尾插   指针尾随
int linklist_addMid(NODE **head,DATA pos,DATA data);  //中插   
void linklist_showAll(const NODE* head);  //遍历
NODE *linklist_find(const NODE *head,DATA data);   //查找指定元素的位置
int linklist_upDate(const NODE *head,DATA old,DATA newdata);   //更新指定位置的元素
int linklist_delete(NODE **head,DATA data);   //单链表删除
void  linklist_destroy(NODE **head);   //单链表销毁
int linklist_reverse(NODE **head);   //单链表反转    头插法


int sclinklist_create(SCNODE **head,DATA data);  //循环单链表创造
int sclinklist_addHead(SCNODE **head,DATA data);  //sc头插
int sclinklist_addTail(SCNODE **head,DATA data);  //sc尾插
SCNODE *sclinklist_findtail(const SCNODE *head);  //查找循环单链表尾节点
void sclinklist_showAll(const SCNODE *head);  //循环单链表遍历
SCNODE* jose_playgame(SCNODE *head,int  num);   //约瑟夫环游戏


int bintree_Create(BinNODE **root,DATA1 data);   //创建
int bintree_Insert(BinNODE **root,DATA1 data);   //插入
BinNODE *bintree_Find(const BinNODE *root,DATA1  data);  //查找

#endif
