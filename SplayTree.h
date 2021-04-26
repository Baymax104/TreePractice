/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 22:59
*@Version
*/

#ifndef TREE_SPLAYTREE_H
#define TREE_SPLAYTREE_H

#include"stdio.h" // ÉìÕ¹Ê÷
#include"stdlib.h"
typedef struct nodeSP {
    int data;
    struct nodeSP *parent;
    struct nodeSP *left;
    struct nodeSP *right;
}Tnode;
void preOrderSP(Tnode *tnode);
void inOrderSP(Tnode *tnode);
void postOrderSP(Tnode *tnode);
void zigSP(Tnode **root, Tnode *tnode);
void zagSP(Tnode **root, Tnode *tnode);
void LLRotationSP(Tnode **root, Tnode *tnode);
void RRRotationSP(Tnode **root, Tnode *tnode);
void RLRotationSP(Tnode **root, Tnode *tnode);
void LRRotationSP(Tnode **root, Tnode *tnode);
void splaySP(Tnode **root, Tnode *tnode);
void insertSP(Tnode **root, int data);
void initNodeSP(Tnode **temp);
void createTreeSP(Tnode **root);
void delSP(Tnode **root, int data);
void projectSP(Tnode *root);

#endif //TREE_SPLAYTREE_H
