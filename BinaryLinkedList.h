/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:46
*@Version
*/

#ifndef TREE_BINARYLINKEDLIST_H
#define TREE_BINARYLINKEDLIST_H

#include<stdio.h> // ��������
#include<stdlib.h>
typedef struct nodeBL
{
    int data;
    struct nodeBL *firstChild;
    struct nodeBL *nextSibling;
}TNODE;
void createTreeBL(TNODE **node);//���򴴽�������
void preOrderBL(TNODE *node);//ǰ�����
void inOrderBL(TNODE *node);//�������
void postOrderBL(TNODE *node);//�������
void emptyTreeBL(TNODE *node);//���ٶ�����

#endif //TREE_BINARYLINKEDLIST_H
