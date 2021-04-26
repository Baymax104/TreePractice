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
    printf("请按前序输入二叉树数据:(按-1结束当前节点子树输入)\n");
    createTree(&root);
    printf("前序遍历结果如下:\n");
    preOrder(root);
    printf("\n中序遍历结果如下:\n");
    inOrder(root);
    printf("\n后序遍历结果如下:\n");
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
