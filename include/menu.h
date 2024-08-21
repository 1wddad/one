#ifndef __MENU_H
#define __MENU_H
#include "slist.h"


void  welcome();
int mainmenu(NODE** head);  //菜单选项
int browsemenu(NODE **head);  //显示
int addmenu(NODE **head);  //添加
int deletemenu(NODE** head);  //删除
int findmenu(NODE* head);  //查找
int fixmenu(NODE* head);  //修改
int playgame();    //休闲

#endif
