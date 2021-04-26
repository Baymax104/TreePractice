/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 22:46
*@Version
*/

#ifndef TREE_AVLTREE_H
#define TREE_AVLTREE_H

#include"stdio.h" // Æ½ºâ¶þ²æÊ÷¡ª¡ªAVLÊ÷
#include"stdlib.h"
#define MAX(x, y) ((x) > (y) ? (x) : (y))
typedef struct nodeAVL {
    int data;
    int height;
    struct nodeAVL *left;
    struct nodeAVL *right;
}Tnode;
int getHeightAVL(Tnode *node);
void initTnodeAVL(Tnode **node);
void singleLeftRotationAVL(Tnode **node);
void singleRightRotationAVL(Tnode **node);
void doubleLeftRotationAVL(Tnode **node);
void doubleRightRotationAVL(Tnode **node);
void insertAVL(Tnode **node, int data);
void createTreeAVL(Tnode **node);
void delNodeAVL(Tnode **node, int data);
void preOrderAVL(Tnode *node);
void inOrderAVL(Tnode *node);
void postOrderAVL(Tnode *node);
void projectAVL(Tnode *node);

#endif //TREE_AVLTREE_H
