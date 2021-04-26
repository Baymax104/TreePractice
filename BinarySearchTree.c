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
        *node=temp;//�ı��˴���Ľڵ�,��Ҫ�������ָ��
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
    TNODE *pCur=*node;//��¼��ɾ���ڵ�
    TNODE *parent=*node;
    int isLeft=0;//��¼ɾ�����Ƿ�����ڵ�
    //����ɾ���ڵ�
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
    //��ɾ���ڵ���Ҷ�ڵ�
    if(pCur->left==NULL&&pCur->right==NULL){
        if(pCur==*node)
            *node=NULL;//�޸��˴���Ľڵ�,��Ҫ�������ָ��
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
    //�ҳ������̽ڵ�
    //�����̽ڵ�:�ȵ�ǰ�ڵ����������е���Сֵ
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
        printf("1)��ӽڵ�\n");
        printf("2)ɾ���ڵ�\n");
        printf("3)ǰ�����\n");
        printf("4)�������\n");
        printf("5)�������\n");
        printf("6)��������\n");
        printf("7)�������ֵ\n");
        printf("8)������Сֵ\n");
        printf("9)ɾ����\n");
        printf("10)�˳�\n");
        printf("���������ѡ��:\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("��������ӵ�����:\n");
                scanf("%d",&insertValue);
                insertBST(&node,insertValue);
                break;
            case 2:
                printf("������ɾ��������:\n");
                scanf("%d",&delValue);
                delBST(&node,delValue);
                break;
            case 3:
                printf("ǰ������������:\n");
                preOrderBST(node);
                printf("\n");
                break;
            case 4:
                printf("��������������:\n");
                inOrderBST(node);
                printf("\n");
                break;
            case 5:
                printf("��������������:\n");
                postOrderBST(node);
                printf("\n");
                break;
            case 6:
                printf("��������ҵ�����:\n");
                scanf("%d",&findValue);
                printf("���ݵ�ַΪ:%p\n",findBST(node,findValue));
                break;
            case 7:
                printf("���ֵΪ:%d\n",findMaxBST(node)->data);
                printf("���ֵ��ַΪ:%p\n",findMaxBST(node));
                break;
            case 8:
                printf("��Сֵ:%d\n",findMinBST(node)->data);
                printf("��Сֵ��ַΪ:%p\n",findMinBST(node));
                break;
            case 9:
                emptyTreeBST(node);
                printf("ɾ���ɹ�\n");
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
    printf("���������������:(��-1��������)\n");
    while(1){
        scanf("%d",&data);
        if(data==-1)
            break;
        insertBST(node,data);
    }
}
