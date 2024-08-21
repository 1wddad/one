#include "slist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int linklist_create(NODE **head,DATA data)  //单链表创造
{
    NODE *p=(NODE*)malloc(sizeof(NODE));  //为指针变量p开辟内存空间
    if(!p)  //没有开辟成功
    {
        return -1;
    }
    p->data=data;   //开辟成功
    p->next=NULL;
    *head=p;  //头指针指向p指针
    return 0;
}


int linklist_addHead(NODE **head,DATA data)   //头插
{
    NODE *p=(NODE *)malloc(sizeof(NODE));
    if(!p)
    {
        return -1;
    }
    p->data=data;
    p->next=*head;
    *head=p;
    return 0;
}


int linklist_addTail(NODE **head,DATA data)  //尾插   指针尾随
{
    NODE *pNew=(NODE *)malloc(sizeof(NODE));  //未新结点开辟内存空间
    if(!pNew)
    {
        return -1;
    }
    pNew->data=data;
    pNew->next=NULL;
    NODE *p=*head,*q=NULL;   //p指向head结点  ，q初始化
    if(!p)   //链表为空
    {
        *head=pNew;  //pNew 为第一个结点
        return 0;
    }
    while(p)  //链表不为空，循环遍历链表   直到p=NULL, 退出循环,q是pNew的前驱结点
    {
        q=p;
        p=p->next;  //p指针后移
    }
    q->next=pNew;  
    return 0;
}


int linklist_addMid(NODE **head,DATA pos,DATA data)  //中插   
{
    NODE *pNew=(NODE *)malloc(sizeof(NODE));   //为pNew结点开辟内存空间
    if(!pNew)
    {
        return -1;
    }
    pNew->data=data;
    pNew->next=NULL;
    NODE *p=*head,*q=NULL;
    if(!p)    //链表为空
    {
        *head=pNew;
        return 0;
    }
    if(memcmp(&(p->data),&pos,sizeof(DATA)==0))   //链表只有一个结点
    {
        pNew->next=*head;
        *head=pNew;
        return 0;
    }
    while(p)   //链表中有多个结点,循环遍历
    {
        if(memcmp(&(p->data),&pos,sizeof(DATA))==0)   //当前结点p和pos所指向的元素对比
        {
            pNew->next=p;
            q->next=pNew;
            if(memcmp(&(p->data),&((*head)->data),sizeof(DATA))==0)  //在头结点之前插入数据,链表中有多个结点，但头结点的数据和pos的数据一样（特殊处理）
            {
                pNew->next=p;
                *head=pNew;
            }
            return 0;
        }
        q=p;
        p=p->next;   //指针尾随
    }
    q->next=pNew;
    return 0;
}

void linklist_showAll(const NODE* head)   //遍历
{
     const NODE* p=head;
     int num=0;    
     while(p)
     {
        puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
        printf("   线路=%d---起始点=%s---目的地=%s---当前位置=%s---里程=%f---型号=%s---颜色=%s---价格=%f---车长=%f---车宽=%f---时速=%d\n",p->data.line,p->data.start,p->data.stop, p->data.current,p->data.km,p->data.model,p->data.color,p->data.money,p->data.len,p->data.wid,p->data.speed); 
        puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
        num++;   
        p=p->next;
     }
     printf("总共有%d条记录\n",num);
}


NODE *linklist_find(const NODE *head,DATA data)   //查找指定元素的位置
{
    const NODE *p=head;   
    while(p)
    {  
        if(memcmp(&(p->data),&data,sizeof(DATA))==0)  //相同
        {
            return (NODE *)p;   //返回所对应的地址
        }
        p=p->next;
    }
    return NULL;   //没有指定元素的地址
}


int linklist_upDate(const NODE *head,DATA old,DATA newdata)   //更新指定位置的元素
{
    NODE *p=NULL;  //指针p进行初始化
    if(!(p=linklist_find(head,old)))   //在链表中没有找到old数据所在的结点
    {
        //printf("can not find!!!\n");
        return  -1; 
    }
    p->data=newdata;  //更改数据
    return 0;
}


int linklist_delete(NODE **head,DATA data)   //单链表删除
{
    NODE *p=*head,*q=NULL;
    if(!p)  //链表为空
    {
        return -1;
    }
    if(memcmp(&(p->data),&data,sizeof(DATA))==0)  //单链表有一个结点或两个结点
    {
        *head=p->next;
        free(p);
        return 0;
    }
    while(p)   //单链表至少三个结点
    {
        if(memcmp(&(p->data),&data,sizeof(DATA))==0)
        {
            q->next= p->next;
            free(p);
            return 0;
        }
        q=p;
        p=p->next;   //尾随指针q
    }
    return -1;
}

void  linklist_destroy(NODE **head)   //单链表销毁
{
    NODE *p=*head,*q=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);  //q和p动态变化
    }
    *head=NULL;   //链表为空
    return ;
}


int linklist_reverse(NODE **head)   //单链表反转    头插法
{
    NODE *p=*head;
    if(p==NULL||p->next==NULL)  //链表为空或者只有一个头结点
    {
        return  -1;
    }
    NODE *q=p->next;
    while(q)
    {
       p->next=q->next;    //断链
       q->next=*head;
        *head=q;  //q为头结点
        q=p->next;   //下一个要断链的结点
    }
    return 0;
}



int bintree_Create(BinNODE **root,DATA1 data)   //创建
{
    if(*root)  //根节点存在
    {
        return -1;
    }
    BinNODE *pNew=(BinNODE *)malloc(sizeof(BinNODE));
    if(!pNew)   //申请失败
    {
        return  -1;
    }
    pNew->data=data;
    pNew->left=NULL;
    pNew->right=NULL;
    *root=pNew;   //根节点，指向pNew
    return 0;
}

int bintree_Insert(BinNODE **root,DATA1 data)   //插入
{
    BinNODE *pNew=(BinNODE *)malloc(sizeof(BinNODE));
    if(!pNew)
    {
        return -1;
    }
    pNew->data=data;
    pNew->left=NULL;
    pNew->right=NULL;
    if(!(*root))  //根节点不存在
    {
        *root=pNew;
        return 0;
    }
    BinNODE *p=*root,*q=NULL;
    while(p)   //二叉树有1个或多个结点
    {
        q=p;   //循环退出后，q作为新的根节点
        if(memcmp(&data,&(p->data),sizeof(DATA1))<0)   //当前结点的数据比根节点的数据小
        {
            p=p->left; //往左走
        }
        else if(memcmp(&data,&(p->data),sizeof(DATA1))>0)  //当前结点的数据比根节点的数据大
        {
            p=p->right;  //往右走
        }
    }
    if(memcmp(&data,&(q->data),sizeof(DATA1))<0)  //循环退出后，q作为新的根结点,当前结点的数据比根节点的数据小
    {
        q->left=pNew;   //往左走
    }
    else if(memcmp(&data,&(q->data),sizeof(DATA1))>0)  //当前结点的数据比根节点的数据大
    {
        q->right=pNew;  //往右走
    }
    return 0;
}


BinNODE *bintree_Find(const BinNODE *root,DATA1  data)  //查找
{
    int count=0;
    const BinNODE *p=root;
    while(p)   //根节点存在
    {
        if(memcmp(&data,&(p->data),sizeof(DATA1))<0)   //要查找的数据比根节点的数据小
        {
            printf("数字大了,当前的数据是%d\n",p->data);
            count++;
            p=p->left;
        }
        else if(memcmp(&data,&(p->data),sizeof(DATA1))>0)  //要查找的数据比根节点的数据大
        {
            printf("数字小了,当前的数据是%d\n",p->data);
            count++;
            p=p->right;
        }
        else if(memcmp(&data,&(p->data),sizeof(DATA1))==0)   //查找的数据和根节点的数据一样
        {
             count++;
             printf("count=%d\n",count);         
            return (BinNODE *) p; //找到了要查找的结点的数据层数   
        }
    }
    return NULL;   //没有找到要查找的结点的数据
}


int sclinklist_create(SCNODE **head,DATA data)  //循环单链表创造
{
    if(*head)  //头结点存在  最少有一个结点
    {
        return -1;
    }
    SCNODE *p=(SCNODE*)malloc(sizeof(SCNODE));  //为指针变量p开辟内存空间
    if(!p)  //没有开辟成功
    {
        return -1;
    }
    p->data=data;   //开辟成功
    p->next=p;
    *head=p;  //头指针指向p指针
    return 0;
}



int sclinklist_addHead(SCNODE **head,DATA data)   //头插
{
    SCNODE *tail=sclinklist_findtail(*head);   //tail 指向循环链表表尾
    if(!tail)    //一个结点都没有
    {
        return sclinklist_create(head,data);
    }
    SCNODE *pNew=(SCNODE *)malloc(sizeof(SCNODE));
    if(!pNew)
    {
        return -1;
    }
    pNew->data=data;
    pNew->next=*head;  //pNew为头结点
    tail->next=pNew;
    *head=pNew;    //更新头结点
    return 0;
}


int sclinklist_addTail(SCNODE **head,DATA data)  //尾插   指针尾随
{
    SCNODE *tail=sclinklist_findtail(*head);
    if(!tail)   //一个结点都没有
    {
        sclinklist_create(head,data);   
    }
    SCNODE *pNew=(SCNODE *)malloc(sizeof(SCNODE));  //为新结点开辟内存空间
    if(!pNew)
    {
        return -1;
    }
    pNew->data=data;    //循环链表中有一个结点
    tail->next=pNew;    //pNew为尾结点
    pNew->next=*head;   
    tail=pNew;   //tail 指向尾结点
    SCNODE *p=*head,*q=NULL;   //p指向head结点 ，q初始化
    while(p)  //循环链表不为空
    {
        q=p;
        p=p->next;  //p指针后移
        if(p==*head)  //q指向尾结点处
        {
            break;
        }
    }
    q->next=pNew;   //pNew为尾结点
    tail=pNew;
    pNew->next=*head;    //构成循环链表
    return 0;
}

SCNODE *sclinklist_findtail(const SCNODE *head)  //查找循环单链表尾节点
{
    const SCNODE *p=head,*q=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        if(p==head)
        {
            break;
        }
    }
    return (SCNODE *) q;    //q为尾结点
}


void sclinklist_showAll(const SCNODE *head)  //循环单链表遍历
{
    const SCNODE *p=head;
    while(p)
    {
        puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
        printf("   线路=%d---起始点=%s---目的地=%s---当前位置=%s---里程=%f---型号=%s---颜色=%s---价格=%f---车长=%f---车宽=%f---时速=%d\n",p->data.line,p->data.start,p->data.stop, p->data.current,p->data.km,p->data.model,p->data.color,p->data.money,p->data.len,p->data.wid,p->data.speed); 
        puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
        p=p->next;
        if(p==head)
        {
            break;
        }
    }
    printf("\n");
    return;
}

SCNODE*  jose_playgame(SCNODE *head,int  num)   //约瑟夫游戏
{
    SCNODE *p=head,*q=NULL;
    if(!p)
    {
        return NULL;
    }
    if(p==p->next)   //循环单链表只有一个结点
    {
        return (SCNODE *)p;
    }
    register int i=0;
    for(;i<num-1;i++)
    {
        q=p;
        p=p->next;
    }
    puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
    printf("   delete   线路=%d---起始点=%s---目的地=%s---当前位置=%s---里程=%f---型号=%s---颜色=%s---价格=%f---车长=%f---车宽=%f---时速=%d\n",p->data.line,p->data.start,p->data.stop, p->data.current,p->data.km,p->data.model,p->data.color,p->data.money,p->data.len,p->data.wid,p->data.speed); 
    puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
    q->next=p->next;   //断链
    free(p);  //删除当前p指向的结点
    head=q->next;   //头结点指向新结点
    return jose_playgame(head,num);   //递归调用
}
