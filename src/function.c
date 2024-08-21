#include "function.h"
#include "file.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  //sleep函数要用

int addrecord(NODE** head,int sel)  //添加信息
{
    int  ret = 0;
    if(sel == 1)   //调用头插
    {
        DATA  data ;  //头插
        puts("请输入线路:");
        scanf("%d",&(data.line));
        puts("请输入起始点:");
        scanf("%s",data.start);
        puts("请输入目的地:");
        scanf("%s",data.stop);
        puts("请输入当前位置:");
        scanf("%s",data.current);
        puts("请输入线路里程:");
        scanf("%f",&(data.km));
        puts("请输入车的型号:");
        scanf("%s",data.model);
        puts("请输入车的颜色:");
        scanf("%s",data.color);
        puts("请输入车的价格:");
        scanf("%f",&(data.money));
        puts("请输入车的长度:");
        scanf("%f",&(data.len));
        puts("请输入车的宽度:");
        scanf("%f",&(data.wid));
        puts("请输入车的时速:");
        scanf("%d",&(data.speed));
        ret = linklist_addHead(head,data);
        ret=save(*head);
    }
    if(sel == 2)   //调用尾插
    {
        DATA  data ;  //尾插
        puts("请输入线路:");
        scanf("%d",&(data.line));
        puts("请输入起始点:");
        scanf("%s",data.start);
        puts("请输入目的地:");
        scanf("%s",data.stop);
        puts("请输入当前位置:");
        scanf("%s",data.current);
        puts("请输入线路里程:");
        scanf("%f",&(data.km));
        puts("请输入车的型号:");
        scanf("%s",data.model);
        puts("请输入车的颜色:");
        scanf("%s",data.color);
        puts("请输入车的价格:");
        scanf("%f",&(data.money));
        puts("请输入车的长度:");
        scanf("%f",&(data.len));
        puts("请输入车的宽度:");
        scanf("%f",&(data.wid));
        puts("请输入车的时速:");
        scanf("%d",&(data.speed));
        ret = linklist_addTail(head,data);
        ret = save(*head);  //保存，文件写操作
    }
    if(sel == 3)   //调用中插
    {
        DATA pos;  //中插的位置
        puts("请输入线路:");
        scanf("%d",&(pos.line));
        puts("请输入起始点:");
        scanf("%s",pos.start);
        puts("请输入目的地:");
        scanf("%s",pos.stop);
        puts("请输入当前位置:");
        scanf("%s",pos.current);
        puts("请输入线路里程:");
        scanf("%f",&(pos.km));
        puts("请输入车的型号:");
        scanf("%s",pos.model);
        puts("请输入车的颜色:");
        scanf("%s",pos.color);
        puts("请输入车的价格:");
        scanf("%f",&(pos.money));
        puts("请输入车的长度:");
        scanf("%f",&(pos.len));
        puts("请输入车的宽度:");
        scanf("%f",&(pos.wid));
        puts("请输入车的时速:");
        scanf("%d",&(pos.speed));
        DATA  data ;  //头插，尾插
        puts("请输入线路:");
        scanf("%d",&(data.line));
        puts("请输入起始点:");
        scanf("%s",data.start);
        puts("请输入目的地:");
        scanf("%s",data.stop);
        puts("请输入当前位置:");
        scanf("%s",data.current);
        puts("请输入线路里程:");
        scanf("%f",&(data.km));
        puts("请输入车的型号:");
        scanf("%s",data.model);
        puts("请输入车的颜色:");
        scanf("%s",data.color);
        puts("请输入车的价格:");
        scanf("%f",&(data.money));
        puts("请输入车的长度:");
        scanf("%f",&(data.len));
        puts("请输入车的宽度:");
        scanf("%f",&(data.wid));
        puts("请输入车的时速:");
        scanf("%d",&(data.speed));
        ret=linklist_addMid(head,pos,data);
        ret=save(*head);
    }
    return ret;
}


static int delete_byline(NODE** head,int line)  //按线路删除
{
    NODE* p = *head;
    while(p)
    {
        if(p->data.line == line)   //找到了要删除的数据，退出循环体
              break;
        p=p->next;
    }
    if(!p)
       return -1;
    return linklist_delete(head,p->data);
} 


static int delete_bystop(NODE** head,const char* stop)  //按目的地删除
{
    NODE* p= *head;
    while(p)
    {
        if(strcmp(p->data.stop, stop) == 0)   //找到了要删除的数据，退出循环体
        {
            break;
        }
        p=p->next;
    }
    if(!p)
       return -1;
    return linklist_delete(head,p->data);
}



static int delete_bykm(NODE** head,float km)  //按里程删除
{
    NODE* p= *head;
    while(p)
    {
        if(p->data.km == km)  //找到了要删除的数据，退出循环体
        {
            break;
        }
        p=p->next;
    }
    if(!p)
       return -1;
    return linklist_delete(head,p->data);
}


int deleterecord(NODE** head,int sel)   //删除信息
{
   int num=0;
   do
   {
        puts("请输入num用于退出当前功能");
        scanf("%d",&num);
        if(num==999)
        {
            break;
        }
        if(sel==1)   //线路删除
        {
            int  line = 0;
            puts("请输入要删除的线路:");
            scanf("%d",&line);
            if(delete_byline(head,line) == 0)   //存在
            {
                save(*head);  //保存
                linklist_showAll(*head);
            }
            else   //线路不存在
            {
                puts("你删除的线路不存在");
                puts("please again input");
            }
        }
        if(sel==2)  //里程删除
        {
            float km = 0;
            puts("请输入要删除的里程:");
            scanf("%f",&km);
            if(delete_bykm(head,km) == 0)   //存在
            {
                save(*head);  //保存
                linklist_showAll(*head);
            }
            else   //线路不存在
            {
                puts("你删除的里程不存在");
                puts("please again input");
            }
        }
        if(sel==3)   //目的地删除
        {
            char  stop[10] ={ '\0'};
            puts("请输入要删除的目的地:");
            scanf("%s",stop);
            if(delete_bystop(head,stop) == 0)    //存在
            {
               save(*head);
               linklist_showAll(*head);
            }
            else    //不存在
            {
                puts("你删除的目的地不存在,");
                puts("please again input");
            }
        }
            
    }while(num);   //退出循环体的条件
    return 0;
}



int compare(NODE* p ,NODE* q, int sel)   //比较数组的数据,让sort函数调用它
{
   switch(sel)
   {
       case 1:
            return  p->data.line < q->data.line;  //线路
       case 2:
            return  strcmp(p->data.stop, q->data.stop) < 0;   //目的地
       case 3:
            return  p->data.km < q->data.km;  //里程
       case 4:
            return 0;   //不排序
   }
   return 0;
}



void Sort(NODE* head,int sel)   //从大到小排序
{
    int n=0;
    NODE* p=head;
    while(p)  //用n记录单链表中有多少组数据  ,n为数组中元素的个数
    {
        n++;
        p=p->next;
    }
    NODE **ps = (NODE **)calloc(n,sizeof(NODE *));  //为数组开辟内存空间
    if(!ps)  //没有申请成功
    {
        return ;
    }
    register int i = 0;   //申请成功
    p=head;
    while(p)   //单链表中的数据赋值给ps数组
    {
         ps[i++]=p;
         p=p->next;
    }
    register int j = 0;
    for(i=0;i<n-1;i++)   //冒泡排序
    {
        int m=i;   
        for(j=i+1;j<n;j++)
        {
            if(compare(ps[m],ps[j],sel))   //更换下标
            {
                m=j;
            }
        }
        if(m!=i)//m的下标为j时，交换数据
        {
            NODE *t=ps[i];
            ps[i] = ps[m]; 
            ps[m] = t;
        }
    }
    for(i=0;i<n;i++)   //遍历   ps为二级指针解引用不能用(*ps+i)->data.(成员名)    结果不对，会出现乱码
    {
        puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
        printf("   线路=%d---起始点=%s---目的地=%s---当前位置=%s---里程=%f---型号=%s---颜色=%s---价格=%f---车长=%f---车宽=%f---时速=%d\n",(*(ps+i))->data.line,(*(ps+i))->data.start,(*(ps+i))->data.stop, (*(ps+i))->data.current,(*(ps+i))->data.km,(*(ps+i))->data.model,(*(ps+i))->data.color,(*(ps+i))->data.money,(*(ps+i))->data.len,(*(ps+i))->data.wid,(*(ps+i))->data.speed); 
        puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
    }
    free(ps);
}



NODE * Find_byline(NODE* head,int line)  //按线路查找
{
    NODE* p = head;
    while(p)
    {
        if(p->data.line == line)   //找到了要删除的数据，退出循环体
              break;
        p=p->next;
    }
    if(!p)
       return NULL;
    return linklist_find(head,p->data);
} 


NODE * Find_bystop(NODE* head,const char* stop)  //按目的地查找
{
    NODE* p= head;
    while(p)
    {
        if(strcmp(p->data.stop, stop) == 0)   //找到了要删除的数据，退出循环体
        {
            break;
        }
        p=p->next;
    }
    if(!p)
       return NULL;
    return linklist_find(head,p->data);
}



NODE * Find_bykm(NODE* head,float km)  //按里程查找
{
    NODE* p= head;
    while(p)
    {
        if(p->data.km == km)  //找到了要删除的数据，退出循环体
        {
            break;
        }
        p=p->next;
    }
    if(!p)
       return NULL;
    return linklist_find(head,p->data);
}



int findrecord(NODE* head,int sel)   //查找信息
{
   int num=0;
   do
   {
        puts("请输入num用于退出当前功能:");
        scanf("%d",&num);
        if(num==999)  //退出循环体
        {
            break;
        }
        if(sel==1)   //线路查找
        {
            int  line = 0;
            puts("请输入要查找的线路:");
            scanf("%d",&line);
            NODE *p=Find_byline(head,line);
            if(p)   //存在
            {
                puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
                printf("   线路=%d---起始点=%s---目的地=%s---当前位置=%s---里程=%f---型号=%s---颜色=%s---价格=%f---车长=%f---车宽=%f---时速=%d\n",p->data.line,p->data.start,p->data.stop, p->data.current,p->data.km,p->data.model,p->data.color,p->data.money,p->data.len,p->data.wid,p->data.speed); 
                puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
            }
            else   //线路不存在
            {
                puts("你查找的线路不存在");
                puts("please again input");
            }
        }
        if(sel==2)  //里程查找
        {
            float km = 0;
            printf("请输入要查找的里程:");
            scanf("%f",&km);
            NODE *q=Find_bykm(head,km);
            if(q)   //存在
            {
               puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
               printf("   线路=%d---起始点=%s---目的地=%s---当前位置=%s---里程=%f---型号=%s---颜色=%s---价格=%f---车长=%f---车宽=%f---时速=%d\n",q->data.line,q->data.start,q->data.stop, q->data.current,q->data.km,q->data.model,q->data.color,q->data.money,q->data.len,q->data.wid,q->data.speed); 
               puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
            }
            else   //线路不存在
            {
                puts("你查找的里程不存在");
                puts("please again input");
            }
        }
        if(sel==3)   //目的地查找
        {
            char  stop[10] ={ '\0'};
            puts("请输入要查找的终点:");
            scanf("%s",stop);
            NODE *r=Find_bystop(head,stop);
            if(r)    //存在
            {
               puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
               printf("   线路=%d---起始点=%s---目的地=%s---当前位置=%s---里程=%f---型号=%s---颜色=%s---价格=%f---车长=%f---车宽=%f---时速=%d\n",r->data.line,r->data.start,r->data.stop, r->data.current,r->data.km,r->data.model,r->data.color,r->data.money,r->data.len,r->data.wid,r->data.speed); 
               puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
            }
            else    //不存在
            {
                puts("你查找的终点不存在,");
                puts("please again input");
            }
        }
            
    }while(num);   //退出循环体的条件
    return 0;
}



int fixrecord(NODE* head,int sel)   //修改信息
{
   int num=0;
   do
   {
        puts("请输入num用于退出当前功能:");
        scanf("%d",&num);
        if(num==999)  //退出循环体
        {
            break;
        }
        if(sel==2)   //线路修改
        {
            int  pos = 0;
            puts("请输入旧的线路:");
            scanf("%d",&pos);
            NODE *p=Find_byline(head,pos);
            int newdata=0;
            puts("请输入新的线路:");
            scanf("%d",&newdata);
            if(p)   //存在
            {
                p->data.line=newdata;
                puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
                printf("   线路=%d---起始点=%s---目的地=%s---当前位置=%s---里程=%f---型号=%s---颜色=%s---价格=%f---车长=%f---车宽=%f---时速=%d\n",p->data.line,p->data.start,p->data.stop, p->data.current,p->data.km,p->data.model,p->data.color,p->data.money,p->data.len,p->data.wid,p->data.speed); 
                puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
            }
            else   //线路不存在
            {
                puts("你要修改的线路不存在");
                puts("please again input");
            }
        }
        if(sel==1)   //里程修改
        {
            float km=0;
            puts("请输入旧的里程:");
            scanf("%f",&km);
            puts("请输入新的里程:");
            float newkm=0;
            scanf("%f",&newkm);
            NODE *r=Find_bykm(head,km);
            if(r)    //存在
            {
                r->data.km=newkm;
                puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
                printf("   线路=%d---起始点=%s---目的地=%s---当前位置=%s---里程=%f---型号=%s---颜色=%s---价格=%f---车长=%f---车宽=%f---时速=%d\n",r->data.line,r->data.start,r->data.stop, r->data.current,r->data.km,r->data.model,r->data.color,r->data.money,r->data.len,r->data.wid,r->data.speed); 
                puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
            }
            else    //不存在
            {
                puts("你修改的里程不存在,");
                puts("please again input");
            }
        }
            
    }while(num);   //退出循环体的条件
    return 0;
}


void MyFun_Binary()  //树型是只有斜左子树  和斜右子树
{
    BinNODE *root=NULL;  //根节点初始化
    srand((unsigned int)time(NULL));  //时间戳 随机种子用来产生随机数
    bintree_Create(&root,50);  //50做为根节点
    int arr[49]={0};
    for(register int i=48;i>=0;i--)
    {
        arr[i]=i+1;
        bintree_Insert(&root,arr[i]);  //数组中的数据转到树中   49-1
    }
    int array[50]={0};
    for(int i=0;i<50;i++)
    {
        array[i]=51+i;
        bintree_Insert(&root,array[i]);  //数组中的数据转到树中   51-100
    }
    int num=0;
    num=rand()%10+1;   //1-100
    BinNODE *q=bintree_Find(root,num);  //调用Find函数
    printf("rand(num)=%d\n",q->data);   //输出随机数
}

void MyFun_Binary_Search()  //二分查找的思想  猜数字
{
    int arr[100];   
    int len=(int)(sizeof(arr)/sizeof(4));   //数组长度
    printf("len=%d\n",len);
    memset(arr,0,400);   //数组全为0
    srand((unsigned int)time(NULL));   //时间戳   减免重复性和不确定性      确保随机性
    int x=0;
    x=rand()%100+1;  //1-100之间的随机数   rand()%100为0-99
    int count=0;  //纪录猜了几次
    int low=0,high=99;  //low数组最左侧的下标   high  数组最右侧的下标
    int  n=0;
    scanf("%d",&n);    //1-100时才会进入进入下面的循环
    puts("");
    if(n>=1&&n<=100)
    {
        while(low<=high)  //high>low 时退出循环条件
        {
            scanf("%d",&n);
            int mid=(low+high)/2;  //每次循环  中间下标更换
            if(n==x)
            {
                arr[mid]=n;
                printf("恭喜你猜对了,随机数是%d\n",arr[mid]);  //猜对后，退出循环体
                count++;
                break;
            }
            else if(n>x)
            {
                arr[mid]=n;
                printf("你猜大了,你猜的是%d\n",arr[mid]);           
                high=mid-1;   //high  移位
                count++;
            }
            else if(n<x)
            {
                arr[mid]=n;
                printf("你猜小了,你猜的是%d\n",arr[mid]);
                low=mid+1;  //low  移位
                count++;
            }
        }
        printf("count=%d\n",count);
    }
    else 
    {
        puts("you input error! please again input:");
    }
}


void  MyFun_Game()  //约瑟夫游戏
{
    SCNODE *head=NULL;
    while(1)
    {
        DATA  data ;  //头插
        puts("请输入线路:");
        scanf("%d",&(data.line));
        puts("请输入起始点:");
        scanf("%s",data.start);
        puts("请输入目的地:");
        scanf("%s",data.stop);
        puts("请输入当前位置:");
        scanf("%s",data.current);
        puts("请输入线路里程:");
        scanf("%f",&(data.km));
        puts("请输入车的型号:");
        scanf("%s",data.model);
        puts("请输入车的颜色:");
        scanf("%s",data.color);
        puts("请输入车的价格:");
        scanf("%f",&(data.money));
        puts("请输入车的长度:");
        scanf("%f",&(data.len));
        puts("请输入车的宽度:");
        scanf("%f",&(data.wid));
        puts("请输入车的时速:");
        scanf("%d",&(data.speed));
        sclinklist_addHead(&head,data);
        DATA  data1 ;  //头插
        puts("请输入线路:");
        scanf("%d",&(data1.line));
        puts("请输入起始点:");
        scanf("%s",data1.start);
        puts("请输入目的地:");
        scanf("%s",data1.stop);
        puts("请输入当前位置:");
        scanf("%s",data1.current);
        puts("请输入线路里程:");
        scanf("%f",&(data1.km));
        puts("请输入车的型号:");
        scanf("%s",data1.model);
        puts("请输入车的颜色:");
        scanf("%s",data1.color);
        puts("请输入车的价格:");
        scanf("%f",&(data1.money));
        puts("请输入车的长度:");
        scanf("%f",&(data1.len));
        puts("请输入车的宽度:");
        scanf("%f",&(data1.wid));
        puts("请输入车的时速:");
        scanf("%d",&(data1.speed));
        sclinklist_addTail(&head,data1);
        int num=0;
        scanf("%d",&num);
        if(num==999)    //用于退出循环
        {
            break;
        }
    }
    puts("");
    puts("|------------------------------------------------------------------------jose_game--------------------------------------------------------------------------------------------|");   //重新一个循环链表
    SCNODE *p=head;
    sclinklist_showAll(p);
    sleep(3);
    puts("please input num1  用于实现约瑟夫游戏");
    int num1=0;
    scanf("%d",&num1);
    SCNODE* women=jose_playgame(p,num1);   //只剩下一组1数据
    puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
    printf("   finall   线路=%d---起始点=%s---目的地=%s---当前位置=%s---里程=%f---型号=%s---颜色=%s---价格=%f---车长=%f---车宽=%f---时速=%d\n",women->data.line,women->data.start,women->data.stop, women->data.current,women->data.km,women->data.model,women->data.color,women->data.money,women->data.len,women->data.wid,women->data.speed); 
    puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
}








    
