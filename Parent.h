/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:40
*@Version
*/

#ifndef TREE_PARENT_H
#define TREE_PARENT_H

#include<stdio.h> // ˫�ױ�ʾ��
#include<stdlib.h>
#define MAX 100
typedef struct nodeP//�ڵ�
{
    int data;
    int parent;
}Node;
typedef struct treeP//���ṹ
{
    Node nodes[MAX];
    int cnt;
}Tree;
void initTreeP(Tree *ptrTree);
void addTreeP(int data,int parent,Tree *ptrTree);
void createTreeP(Tree *ptrTree);
void preOrderP(Tree *ptrTree,int root);
void postOrderP(Tree *ptrTree,int root);
void projectP(Tree *ptrTree);
void delTreeP(Tree *ptrTree,int index);

#endif //TREE_PARENT_H
