/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:44
*@Version
*/

#ifndef TREE_CHILDANDSIBLING_H
#define TREE_CHILDANDSIBLING_H

#include<stdio.h> // 孩子兄弟表示法
#include<stdlib.h>
#define MAX 100
typedef struct nodeCS
{
    int data;
    int firstChild;
    int nextSibling;
}Node;
typedef struct treeCS
{
    Node node[MAX];
    int cnt;
}Tree;
void createTreeCS(Tree *ptrTree);
void initTreeCS(Tree *ptrTree);
void addTreeCS(int data,int parent,Tree *ptrTree);
void preOrderCS(Tree *ptrTree,int root);
void postOrderCS(Tree *ptrTree,int root);
void projectCS(Tree *ptrTree);
void delTreeCS(Tree *ptrTree,int index);

#endif //TREE_CHILDANDSIBLING_H
