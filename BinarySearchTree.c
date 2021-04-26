/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 22:09
*@Version
*/

#include "BinarySearchTree.h"
/*int main()
{
    TNODE *root=NULL;
    createTree(&root);
    project(root);
    return 0;
}*/
TNODE *initTnodeBST()
{
    TNODE *root=(TNODE*)malloc(sizeof(TNODE));
    root->left=NULL;
    root->right=NULL;
    root->data=0;
    return root;
}
void insertBST(TNODE **node,int value)
{
    TNODE *temp=NULL;
    if(!(*node)){
        temp=initTnodeBST();
        temp->data=value;
        *node=temp;//改变了传入的节点,需要传入二级指针
        return;
    }
    if(value<(*node)->data)
        insertBST(&(*node)->left,value);
    else
        insertBST(&(*node)->right,value);
    return;
}
void delBST(TNODE **node,int value)
{
    TNODE *pCur=*node;//记录被删除节点
    TNODE *parent=*node;
    int isLeft=0;//记录删除的是否是左节点
    //查找删除节点
    if(pCur==NULL)
        return;
    while(pCur->data!=value){
        if(value<=pCur->data){
            isLeft=1;
            if(pCur->left){
                parent=pCur;
                pCur=pCur->left;
            }
        }
        else{
            isLeft=0;
            if(pCur->right){
                parent=pCur;
                pCur=pCur->right;
            }
        }
    }
    //若删除节点是叶节点
    if(pCur->left==NULL&&pCur->right==NULL){
        if(pCur==*node)
            *node=NULL;//修改了传入的节点,需要传入二级指针
        else if(isLeft)
            parent->left=NULL;
        else
            parent->right=NULL;
        free(pCur);
    }
    else if(pCur->right==NULL&&pCur->left!=NULL){
        if(pCur==*node)
            *node=(*node)->left;
        else if(isLeft)
            parent->left=pCur->left;
        else
            parent->right=pCur->left;
        free(pCur);
    }
    else if(pCur->left==NULL&&pCur->right!=NULL){
        if(pCur==*node)
            *node=(*node)->right;
        else if(isLeft)
            parent->left=pCur->right;
        else
            parent->right=pCur->right;
        free(pCur);
    }
    else{
        TNODE *successor=getSuccessorBST(pCur);
        if(pCur==*node)
            *node=successor;
        else if(pCur==parent->left)
            parent->left=successor;
        else
            parent->right=successor;
        successor->left=pCur->left;
        free(pCur);
    }
}
TNODE *getSuccessorBST(TNODE *delNode)
{
    //找出中序后继节点
    //中序后继节点:比当前节点大的所有数中的最小值
    TNODE *pCur=delNode->right;
    TNODE *successor=pCur;
    TNODE *sucParent=NULL;
    while(pCur){
        sucParent=successor;
        successor=pCur;
        pCur=pCur->left;
    }
    if(successor!=delNode->right){
        if (sucParent) {
            sucParent->left=successor->right;
            successor->right=delNode->right;
        }
    }
    return successor;
}
void emptyTreeBST(TNODE *node)
{
    if(node){
        emptyTreeBST(node->left);
        emptyTreeBST(node->right);
        free(node);
    }
}
void preOrderBST(TNODE *node)
{
    if(node){
        printf("%d ",node->data);
        preOrderBST(node->left);
        preOrderBST(node->right);
    }
}
void inOrderBST(TNODE *node)
{
    if(node){
        inOrderBST(node->left);
        printf("%d ",node->data);
        inOrderBST(node->right);
    }
}
void postOrderBST(TNODE *node)
{
    if(node){
        postOrderBST(node->left);
        postOrderBST(node->right);
        printf("%d ",node->data);
    }
}
TNODE *findBST(TNODE *node,int value)
{
    if(node==NULL)
        return NULL;
    if(value<node->data)
        return findBST(node->left,value);
    else if(value>node->data)
        return findBST(node->right,value);
    else
        return node;
}
TNODE *findMaxBST(TNODE *node)
{
    if(node==NULL)
        return NULL;
    else if(node->right==NULL)
        return node;
    else
        return findMaxBST(node->right);
}
TNODE *findMinBST(TNODE *node)
{
    if(node==NULL)
        return NULL;
    else if(node->left==NULL)
        return node;
    else
        return findMinBST(node->left);
}
void projectBST(TNODE *node)
{
    int op;
    int insertValue;
    int delValue;
    int findValue;
    do{
        printf("1)添加节点\n");
        printf("2)删除节点\n");
        printf("3)前序遍历\n");
        printf("4)中序遍历\n");
        printf("5)后序遍历\n");
        printf("6)查找数据\n");
        printf("7)查找最大值\n");
        printf("8)查找最小值\n");
        printf("9)删除树\n");
        printf("10)退出\n");
        printf("请输入你的选择:\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("请输入添加的数据:\n");
                scanf("%d",&insertValue);
                insertBST(&node,insertValue);
                break;
            case 2:
                printf("请输入删除的数据:\n");
                scanf("%d",&delValue);
                delBST(&node,delValue);
                break;
            case 3:
                printf("前序遍历结果如下:\n");
                preOrderBST(node);
                printf("\n");
                break;
            case 4:
                printf("中序遍历结果如下:\n");
                inOrderBST(node);
                printf("\n");
                break;
            case 5:
                printf("后序遍历结果如下:\n");
                postOrderBST(node);
                printf("\n");
                break;
            case 6:
                printf("请输入查找的数据:\n");
                scanf("%d",&findValue);
                printf("数据地址为:%p\n",findBST(node,findValue));
                break;
            case 7:
                printf("最大值为:%d\n",findMaxBST(node)->data);
                printf("最大值地址为:%p\n",findMaxBST(node));
                break;
            case 8:
                printf("最小值:%d\n",findMinBST(node)->data);
                printf("最小值地址为:%p\n",findMinBST(node));
                break;
            case 9:
                emptyTreeBST(node);
                printf("删除成功\n");
                break;
            case 10:
                printf("Goodbye\n");
                return;
            default:
                break;
        }
    }while(1);
}
void createTreeBST(TNODE **node)
{
    int data;
    printf("请输入查找树数据:(按-1结束输入)\n");
    while(1){
        scanf("%d",&data);
        if(data==-1)
            break;
        insertBST(node,data);
    }
}
