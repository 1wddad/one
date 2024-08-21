#ifndef __FILE_H
#define __FILE_H
#include "slist.h"

int loading(NODE **head);  //读操作
int save(const NODE* head);  //写操作
#endif
