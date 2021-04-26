/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:42
*@Version
*/

#ifndef TREE_PARENTANDCHILD_H
#define TREE_PARENTANDCHILD_H

#include<stdio.h> // 双亲孩子表示法
#include<stdlib.h>
#define MAX 100
typedef struct nodePC
{
    int childIndex;
    struct nodePC *next;
}Node;
typedef struct tnodePC
{
    int data;
    int parent;
    Node *firstChild;
}TNode;
typedef struct treePC
{
    TNode node[MAX];
    int cnt;
}Tree;
void initTreePC(Tree *ptrTree);
void addTreePC(int data,int parent,Tree *ptrTree);
void createTreePC(Tree *ptrTree);
void preOrderPC(Tree *ptrTree,int root);
void postOrderPC(Tree *ptrTree,int root);
void projectPC(Tree *ptrTree);
void printTreePC(Tree *ptrTree);
void delTreePC(Tree *ptrTree,int index);

#endif //TREE_PARENTANDCHILD_H
