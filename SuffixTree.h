/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:51
*@Version
*/

#ifndef TREE_SUFFIXTREE_H
#define TREE_SUFFIXTREE_H

#include<stdio.h> // 后缀表达式树
#include<stdlib.h>
typedef struct TnodeST
{
    char ch;
    struct TnodeST *left;
    struct TnodeST *right;
}TNODE;
typedef struct SnodeST
{
    TNODE *ptr;
    struct SnodeST *next;
}SNODE;
SNODE *initStackST();
void pushST(SNODE *head,TNODE *node);
TNODE *popST(SNODE *head);
TNODE *createTnodeST(char ch);
void postOrderST(TNODE *node);

#endif //TREE_SUFFIXTREE_H
