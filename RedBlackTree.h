/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 22:53
*@Version
*/

#ifndef TREE_REDBLACKTREE_H
#define TREE_REDBLACKTREE_H

#include"stdio.h" // ºìºÚÊ÷
#include"stdlib.h"
#define RED 0
#define BLACK 1
typedef struct nodeRBT {
    int data;
    int color;
    struct nodeRBT *parent;
    struct nodeRBT *left;
    struct nodeRBT *right;
}Tnode;
void preOrderRBT(Tnode *tnode);
void inOrderRBT(Tnode *tnode);
void postOrderRBT(Tnode *tnode);
void insertRBT(Tnode **root, int data);
void initNodeRBT(Tnode **tnode);
void LLRotationRBT(Tnode **root, Tnode *tnode);
void RRRotationRBT(Tnode **root, Tnode *tnode);
void updateIRBT(Tnode **root, Tnode **node);
void createTreeRBT(Tnode **root);
void delRBT(Tnode **root, int data);
void updateDRBT(Tnode **root, Tnode *child, Tnode *parent);
void projectRBT(Tnode *root);

#endif //TREE_REDBLACKTREE_H
