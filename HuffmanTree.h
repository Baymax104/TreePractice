/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/9 13:45
*@Version
*/

#ifndef TREE_HUFFMANTREE_H
#define TREE_HUFFMANTREE_H

#include"stdio.h" // ¹þ·òÂüÊ÷¡ª¡ª¹¹ÔìÓë±àÂë
#include"stdlib.h"
#include"string.h"
typedef struct {
    int *data;
    int size;
}Heap;
typedef struct nodeHT {
    int weight;
    int parent;
    int left;
    int right;
}Node;
Node *tree;
Heap *heap;
int numberOfWeight = 0;
void pushHT(int data);
int popHT();
void initHeapHT();
void shiftUpHT();
void shiftDownHT();
void swapHT(int *x, int *y);
void initTreeHT();
void createTreeHT();
void findIndexHT(int min1Value, int min2Value, int *min1, int *min2, int current);
void encodeHT(char code[], int weight);
void listTreeHT();
void enterWeightHT();
void listCodeHT();

#endif //TREE_HUFFMANTREE_H
