/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:46
*@Version
*/

#include "BinaryLinkedList.h"
/*int main()
{
    TNODE *root;
    printf("�밴ǰ���������������:(��-1������ǰ�ڵ���������)\n");
    createTree(&root);
    printf("ǰ������������:\n");
    preOrder(root);
    printf("\n��������������:\n");
    inOrder(root);
    printf("\n��������������:\n");
    postOrder(root);
    emptyTree(root);
    return 0;
}*/
void createTreeBL(TNODE **node)
{
    int data;
    scanf("%d",&data);
    getchar();
    if(data==-1)
        *node=NULL;
    else{
        *node=(TNODE*)malloc(sizeof(TNODE));
        (*node)->data=data;
        createTreeBL(&(*node)->firstChild);
        createTreeBL(&(*node)->nextSibling);
    }
}
void preOrderBL(TNODE *node)
{
    if(node){
        printf("%d ",node->data);
        preOrderBL(node->firstChild);
        preOrderBL(node->nextSibling);
    }
}
void postOrderBL(TNODE *node)
{
    if(node){
        postOrderBL(node->firstChild);
        postOrderBL(node->nextSibling);
        printf("%d ",node->data);
    }
}
void emptyTreeBL(TNODE *node)
{
    if(node){
        emptyTreeBL(node->firstChild);
        emptyTreeBL(node->nextSibling);
        free(node);
    }
}
void inOrderBL(TNODE *node)
{
    if(node){
        inOrderBL(node->firstChild);
        printf("%d ",node->data);
        inOrderBL(node->nextSibling);
    }
}
