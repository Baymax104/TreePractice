/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 22:09
*@Version
*/

#ifndef TREE_BINARYSEARCHTREE_H
#define TREE_BINARYSEARCHTREE_H


#include<stdio.h> // ¶þ²æ²éÕÒÊ÷
#include<stdlib.h>
typedef struct TnodeBST
{
    int data;
    struct TnodeBST *left;
    struct TnodeBST *right;
}TNODE;
TNODE *initTnodeBST();
void insertBST(TNODE **node,int value);
void delBST(TNODE **node,int value);
TNODE *getSuccessorBST(TNODE *delNode);
void emptyTreeBST(TNODE *node);
void preOrderBST(TNODE *node);
void inOrderBST(TNODE *node);
void postOrderBST(TNODE *node);
TNODE *findBST(TNODE *node,int value);
TNODE *findMaxBST(TNODE *node);
TNODE *findMinBST(TNODE *node);
void projectBST(TNODE *node);
void createTreeBST(TNODE **node);

#endif //TREE_BINARYSEARCHTREE_H
