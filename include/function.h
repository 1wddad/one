#ifndef __FUNCTION_H
#define __FUNCTION_H
#include "slist.h"

int addrecord(NODE **head,int sel);  //添加信息
int deleterecord(NODE **head,int sel);  //删除信息
int compare(NODE* p ,NODE* q, int sel);   //比较数组的数据,让sort函数调用它
void Sort(NODE*head,int sel); //排序
int findrecord(NODE* head,int sel);   //查找信息
int fixrecord(NODE* head,int sel);   //修改信息
void MyFun_Binary();  //查看随机数在树中的位置
void MyFun_Binary_Search() ;  //猜数
void  MyFun_Game();  //约瑟夫游戏
#endif
