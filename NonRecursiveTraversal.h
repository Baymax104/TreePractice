/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:49
*@Version
*/

#ifndef TREE_NONRECURSIVETRAVERSAL_H
#define TREE_NONRECURSIVETRAVERSAL_H

#include<stdio.h> // �������ǵݹ����
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
void createTreeNRT(TNODE **node);//���򴴽�������
void emptyTreeNRT(TNODE *node);//���ٶ�����
void preOrderNRT(TNODE *node);//ǰ�����
void inOrderNRT(TNODE *node);//�������
void postOrderNRT(TNODE *node);//�������
void levelOrderNRT(TNODE *node);//��α���
//ջ����
SNODE *initStackNRT();
void pushNRT(SNODE *head,TNODE *node);
TNODE *popNRT(SNODE *head);
int isEmptySNRT(SNODE *head);
//���в���
QNODE *initQueueNRT();
void enqueueNRT(QNODE *head,TNODE *node);
TNODE *dequeueNRT(QNODE *head);
int isEmptyQNRT(QNODE *head);

#endif //TREE_NONRECURSIVETRAVERSAL_H
