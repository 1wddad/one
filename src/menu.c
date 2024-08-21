#include "menu.h"
#include "function.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>


void welcome(void)  //欢迎界面
{
      puts("***************************************************");
      puts("***************************************************");
      puts("***************************************************");
      puts("*****                                         *****");
      puts("*****                                         *****");
      puts("***尊敬的用户您好!感谢您成为我们第6666666名用户 ***");
      puts("****          欢迎使用智能汽车驾驶系统         ****");
      puts("****            我们与您一路同行               ****");
      puts("*****                                         *****");
      puts("*****              version-1.1.0              *****");
      puts("*****                                         *****");
      puts("*****                                         *****");
      puts("***************************************************");
      puts("***************************************************");
      puts("******************按任意键继续*********************");   
      getchar(); 
}


int mainmenu(NODE** head)    //菜单选项
{
      puts("**********************");
      puts("***** 1.显示信息  *****");      
      puts("***** 2.添加信息  *****");  
      puts("***** 3.删除信息  *****");   
      puts("***** 4.查询信息  *****");   
      puts("***** 5.修改信息  *****");   
      puts("***** 6.休闲时刻  *****");    
      puts("*****   0.退出    *****");   
      puts("***********************"); 
      int num=0;
      scanf("%d",&num);
      switch(num)
      {
            case  0:
            return 0;
            case  1:  browsemenu(head);  //显示 
            break; 
            case  2:  addmenu(head);  //添加
            break; 
            case  3:  deletemenu(head);  //删除
            break; 
            case  4:  findmenu(*head);  //查找
            break; 
            case  5:  fixmenu(*head);  //修改
            break; 
            case  6:  playgame();   //休闲
            break;
            default :
            puts("输入有误！请重新输入");
      }
}




int browsemenu(NODE** head)    //显示菜单  排序
{
      puts("**************************");
      puts("****    1.线路排序     ****");
      puts("****    2.目的地排序   ****");
      puts("****    3.里程排序     ****");
      puts("****    4.不排序       ****");
      puts("****    0.返回上一级   ****");  //返回上一级
      puts("**************************");  
      puts("");
      int  sel = 0;
      printf("请选择0~4:\n");
      scanf("%d",&sel);
      switch(sel)
      {
            case 0:   return 0;
            case 1: Sort(*head,sel);    //线路
            break;
            case 2: Sort(*head,sel);  //目的地
            break;
            case 3: Sort(*head,sel);  //里程
            break;
            case 4: Sort(*head,sel);   //不排序
            break;
            default:
            puts("输入有误！请重新输入");
      }
      return  sel;   
}


int addmenu(NODE** head)   //添加   添加完后遍历
{
      puts("**************************");
      puts("***      1.头插       ****");
      puts("***      2.尾插       ****");
      puts("***      3.中插       ****");
      puts("***    0.返回上一级    ****");
      puts("**************************");
      puts("");
      int sel=0;
      printf("请选择0~3:\n");
      scanf("%d",&sel);
      switch (sel)
      {
            case  0: return 0;
            case  1: addrecord(head,sel);  //头插
            linklist_showAll(*head);
            linklist_reverse(head);
            puts("");
            linklist_showAll(*head);
            break;
            case  2: addrecord(head,sel);   //尾插
            linklist_showAll(*head);
            linklist_reverse(head);
            puts("");
            linklist_showAll(*head);
            break;
            case  3: addrecord(head,sel);  //中插
            linklist_showAll(*head);
            linklist_reverse(head);
            puts("");
            linklist_showAll(*head);
            break;
            default:
            puts("输入有误！请重新输入");
      }
}



int deletemenu(NODE** head)  //删除
{
      puts("**************************");
      puts("***    1.按线路删除    ****");
      puts("***    2.按里程删除    ****");
      puts("***    3.按目的地删除  ****");
      puts("***    0.返回上一级    ****");
      puts("**************************");
      puts("");
      int sel=0;
      printf("请选择0~3:\n");
      scanf("%d",&sel);
      switch (sel)
      {
            case  0: return 0;
            case 1: deleterecord(head,sel);  //线路
            break;
            case 2: deleterecord(head,sel);  //里程
            break;
            case 3: deleterecord(head,sel); //目的地
            break;        
            default:
            puts("输入有误！请重新输入");
      }
      return sel;
}



int findmenu(NODE* head)  //查找
{
      puts("**************************");
      puts("***    1.按线路查找    ****");
      puts("***    2.按里程查找    ****");
      puts("***    3.按终点查找    ****");
      puts("***    0.返回上一级    ****");
      puts("**************************");
      puts("");
      int sel=0;
      printf("请选择0~3:\n");
      scanf("%d",&sel);
      switch (sel)
      {
            case 0: return 0;
            case 1: findrecord(head,sel);  //线路
            // save(head);
            // loading(&head);
            break;
            case 2: findrecord(head,sel);  //里程
            // save(head);
            // loading(&head);

            break;
            case 3: findrecord(head,sel);   //终点
            // save(head);
            // loading(&head);

            break;
            default:
            puts("输入有误！请重新输入");
      }
      return sel;
}


int fixmenu(NODE* head)  //修改
{
      puts("**************************");
      puts("***    1.里程修改    ****");
      puts("***     2.线路修改     ****");
      puts("***    0.返回上一级    ****");
      puts("**************************");
      puts("");
      int sel=0;
      printf("请选择0~2:\n");
      scanf("%d",&sel);
      switch (sel)
      {
            case  0: return 0;
            case  1:fixrecord(head,sel);   //里程
            break;
            case  2:fixrecord(head,sel);   //线路 
            break;
            default:
            puts("输入有误！请重新输入");
      }
      return sel;
}



int playgame()    //休闲
{
      puts("**************************");
      puts("***    1.约瑟夫游戏   ****");
      puts("***    2.猜数字     ****");
      puts("***  3.随机数在树中的位置  ****");
      puts("***    0.返回上一级   ****");
      puts("**************************");
      puts("");
      int sel=0;
      printf("请选择0~3:\n");
      scanf("%d",&sel);
      switch (sel)
      {
            case  0: return 0;
            case  1:MyFun_Game();
            break;
            case  2: MyFun_Binary_Search();
            break;
            case  3:MyFun_Binary();
            break;
            default:
            puts("输入有误！请重新输入");
      }
      return sel;
}
