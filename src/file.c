#include "file.h"
#include <stdio.h>
#include <stdlib.h>
int loading(NODE **head)  //文件读操作
{
    FILE *fp = fopen("car.txt","r");  //二进制读
    if(!fp)  //打开失败
    {
        return -1;
    }
    NODE *p=*head,*q=*head; //p和q都指向头
    if(fread(p,sizeof(NODE),1,fp)!=1||(!p))  //读失败
    {
        puts("file  read  failed");
        fclose(fp);
        return -1;
    }
    p=q;
    while(fread(&(p -> data),sizeof(NODE),1,fp)==1)   //读成功
    {
        puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
        printf("   线路=%d---起始点=%s---目的地=%s---当前位置=%s---里程=%f---型号=%s---颜色=%s---价格=%f---车长=%f---车宽=%f---时速=%d\n",p->data.line,p->data.start,p->data.stop, p->data.current,p->data.km,p->data.model,p->data.color,p->data.money,p->data.len,p->data.wid,p->data.speed);
        p=p->next;
        puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
        if(p==NULL)
        {
            break;
        }
        //puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
        /*
        p->next=(NODE *)malloc(sizeof(NODE));   //为下个结点开辟内存空间
        p=p->next;  //移位
        q=q->next;
        if(q==NULL)
        {
            free(p);  //释放p==NULL时的结点
            break;
        }
    }
    p=*head; 
    //NODE *q=NULL;
    while(1)    //遍历
    {
      //  q=p;
        //p=p->next;
        puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
        printf("   线路=%d---起始点=%s---目的地=%s---当前位置=%s---里程=%f---型号=%s---颜色=%s---价格=%f---车长=%f---车宽=%f---时速=%d\n",p->data.line,p->data.start,p->data.stop, p->data.current,p->data.km,p->data.model,p->data.color,p->data.money,p->data.len,p->data.wid,p->data.speed);
        p=p->next;
        puts("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
        if(p==NULL)
        {
            break;
        }
    }
    */
    }
    fclose(fp);   //关闭
    return 0;
}


int save(const NODE* head)   //文件写操作
{
    if(!head)
    {
       return -1;
    }
    FILE *fp = fopen("car.txt","w");   //二进制写
    if(!fp)  //打开失败
    {
        return -1;
    }
    NODE* p = (NODE *)head; 
    if(fwrite(p,sizeof(NODE),1,fp)!=1||(!p))  //写失败
    {
        puts("file  write  failed");
        fclose(fp);
        return -1;
    } 
    while(p)   //成功
    {
        fwrite(&(p -> data),sizeof(NODE),1,fp);
        p=p->next;
    }
    fclose(fp);
    return 0;
}
