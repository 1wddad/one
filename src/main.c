#include "slist.h"
#include "function.h"
#include "menu.h"
#include "file.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>    //sleep和system函数的库
#include <stdlib.h>

int main(int argc,char **argv)
{
    
    if(argc<2)
    {
        printf("you input error!please according %s user and password input\n",argv[0]);
    }
    if(strcmp(argv[1],"liu")==0&&strcmp(argv[2],"ldh010724qwer")==0)    //用户名和密码正确
    { 	
        NODE* head = NULL;
        welcome();  //欢迎界面
		system("aplay 1.wav");   //aplay 音频播放命令
        while(1)   //为假退出循环体,菜单选项
        {
            if(mainmenu(&head)==0)
            {
                break;
            }
        }
        puts("|--------------------------------------------------------------------------------读取所有信息列表-------------------------------------------------------------------------------|");
        loading(&head);  //读文件
        
        linklist_destroy(&head);  //销毁
        puts("------------------------------------------------------------------------------------清空信息------------------------------------------------------------------------------------");
        linklist_showAll(head);  //遍历
        
        puts("");
        puts("");
        puts("");
        sleep(5);   //5秒后退出系统
        puts("--------------------------------------------------------------------------------感谢您的使用!谢谢--------------------------------------------------------------------------------");
        system("aplay 2.wav");
    }
    else //用户名和密码错误
    {
        printf("pleasse check user and password\n");
    } 
    return 0;
} 
