/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:46
*@Version
*/

#ifndef TREE_BINARYLINKEDLIST_H
#define TREE_BINARYLINKEDLIST_H

#include<stdio.h> // 二叉链表
#include<stdlib.h>
typedef struct nodeBL
{
    int data;
    struct nodeBL *firstChild;
    struct nodeBL *nextSibling;
}TNODE;
void createTreeBL(TNODE **node);//先序创建二叉树
void preOrderBL(TNODE *node);//前序遍历
void inOrderBL(TNODE *node);//中序遍历
void postOrderBL(TNODE *node);//后序遍历
void emptyTreeBL(TNODE *node);//销毁二叉树

#endif //TREE_BINARYLINKEDLIST_H
