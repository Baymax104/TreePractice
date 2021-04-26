/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:49
*@Version
*/

#ifndef TREE_NONRECURSIVETRAVERSAL_H
#define TREE_NONRECURSIVETRAVERSAL_H

#include<stdio.h> // 二叉树非递归遍历
#include<stdlib.h>
typedef struct TnodeNRT
{
    int data;
    struct TnodeNRT *left;
    struct TnodeNRT *right;
}TNODE;
typedef struct SnodeNRT
{
    TNODE *ptr;
    struct SnodeNRT *next;
}SNODE;
typedef struct QnodeNRT
{
    TNODE *ptr;
    struct QnodeNRT *next;
}QNODE;
void createTreeNRT(TNODE **node);//先序创建二叉树
void emptyTreeNRT(TNODE *node);//销毁二叉树
void preOrderNRT(TNODE *node);//前序遍历
void inOrderNRT(TNODE *node);//中序遍历
void postOrderNRT(TNODE *node);//后序遍历
void levelOrderNRT(TNODE *node);//层次遍历
//栈操作
SNODE *initStackNRT();
void pushNRT(SNODE *head,TNODE *node);
TNODE *popNRT(SNODE *head);
int isEmptySNRT(SNODE *head);
//队列操作
QNODE *initQueueNRT();
void enqueueNRT(QNODE *head,TNODE *node);
TNODE *dequeueNRT(QNODE *head);
int isEmptyQNRT(QNODE *head);

#endif //TREE_NONRECURSIVETRAVERSAL_H
