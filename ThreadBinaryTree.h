/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 22:38
*@Version
*/

#ifndef TREE_THREADBINARYTREE_H
#define TREE_THREADBINARYTREE_H

#include<stdio.h> // ����������
#include<stdlib.h>
typedef struct TnodeTBT
{
    int data;
    int Ltag;
    int Rtag;
    struct TnodeTBT *left;
    struct TnodeTBT *right;
}TNODE;
void createTreeTBT(TNODE **node);
//����������
void createInThreadTBT(TNODE *root);
void inThreadTBT(TNODE *node,TNODE **pre);
//�������
void inOrderTBT(TNODE *node);
TNODE *getFirstITBT(TNODE *node);
TNODE *getNextITBT(TNODE *node);
//ǰ��������
void createPreOrderTBT(TNODE *node);
void preThreadTBT(TNODE *node,TNODE **pre);
//ǰ�����
void preOrderTBT(TNODE *node);
void projectTBT(TNODE *root);

#endif //TREE_THREADBINARYTREE_H
