/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 22:38
*@Version
*/

#include "ThreadBinaryTree.h"
/*int main()
{
    TNODE *root;
    printf("�밴ǰ���������������:(��-1������ǰ�ڵ���������)\n");
    createTreeTBT(&root);
    projectTBT(root);
    return 0;
}*/
void createTreeTBT(TNODE **node)
{
    int data;
    scanf("%d",&data);
    if(data==-1)
        *node=NULL;
    else{
        *node=(TNODE*)malloc(sizeof(TNODE));
        (*node)->data=data;
        (*node)->Ltag=0;
        (*node)->Rtag=0;
        createTreeTBT(&(*node)->left);
        createTreeTBT(&(*node)->right);
    }
}
void createInThreadTBT(TNODE *root)
{
    TNODE *pre=NULL;
    if(root){
        inThreadTBT(root,&pre);
        pre->right=NULL;
        pre->Rtag=1;
    }
}
void inThreadTBT(TNODE *node,TNODE **pre)
{
    if(node){
        inThreadTBT(node->left,pre);
        if(node->left==NULL){
            node->left=*pre;
            node->Ltag=1;
        }
        if((*pre)&&(*pre)->right==NULL){
            (*pre)->right=node;
            (*pre)->Rtag=1;
        }
        *pre=node;
        inThreadTBT(node->right,pre);
    }
}
void inOrderTBT(TNODE *node)
{
    TNODE *p=getFirstITBT(node);
    while(p){
        printf("%d ",p->data);
        p=getNextITBT(p);
        if(p->right==NULL){
            printf("%d",p->data);
            break;
        }
    }
}
TNODE *getFirstITBT(TNODE *node)
{
    TNODE *current=node;
    if(current==NULL)
        return NULL;
    while(current->Ltag!=1)
        current=current->left;
    return current;
}
TNODE *getNextITBT(TNODE *node)
{
    TNODE *current=node;
    if(current->Rtag==1)
        current=current->right;
    else{
        current=current->right;
        while(current->Ltag!=1)
            current=current->left;
    }
    return current;
}
void createPreOrderTBT(TNODE *node)
{
    TNODE *pre=NULL;
    if(node){
        preThreadTBT(node,&pre);
        pre->right=NULL;
        pre->Rtag=1;
    }
}
void preThreadTBT(TNODE *node,TNODE **pre)
{
    if(node){
        if(node->left==NULL){
            node->left=*pre;
            node->Ltag=1;
        }
        if((*pre)&&(*pre)->right==NULL){
            (*pre)->right=node;
            (*pre)->Rtag=1;
        }
        *pre=node;
        if(node->Ltag==0)
            preThreadTBT(node->left,pre);
        if(node->Rtag==0)
            preThreadTBT(node->right,pre);
    }
}
void preOrderTBT(TNODE *node)
{
    TNODE *p=node;
    while(p){
        printf("%d ",p->data);
        if(p->Ltag==0)
            p=p->left;
        else
            p=p->right;
    }
}
void projectTBT(TNODE *root) {
    int op;
    //������������,�ڵ��еı�־λ�Ѿ����ı�,��Ҫ��������,����Ҫ��ʼ��ÿ���ڵ�ı�־λ
    printf("1)����������\n");
    printf("2)ǰ��������\n");
    printf("3)�˳�\n");
    printf("���������ѡ��:\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            printf("����������������������:\n");
            createInThreadTBT(root);
            inOrderTBT(root);
            break;
        case 2:
            printf("ǰ��������������������:\n");
            createPreOrderTBT(root);
            preOrderTBT(root);
            break;
        case 3:
            printf("Goodbye\n");
            return;
        default:
            break;
    }
}
