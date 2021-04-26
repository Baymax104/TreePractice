/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:49
*@Version
*/

#include "NonRecursiveTraversal.h"
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
    printf("\n��α����������:\n");
    levelOrder(root);
    emptyTree(root);
    return 0;
}*/
void createTreeNRT(TNODE **node)
{
    int data;
    scanf("%d",&data);
    getchar();
    if(data==-1)
        *node=NULL;
    else{
        *node=(TNODE*)malloc(sizeof(TNODE));
        (*node)->data=data;
        createTreeNRT(&((*node)->left));
        createTreeNRT(&((*node)->right));
    }
}
void emptyTreeNRT(TNODE *node)
{
    if(node){
        emptyTreeNRT(node->left);
        emptyTreeNRT(node->right);
        free(node);
    }
}
SNODE *initStackNRT()
{
    SNODE *head=(SNODE*)malloc(sizeof(SNODE));
    head->next=NULL;
    return head;
}
void pushNRT(SNODE *head,TNODE *node)
{
    SNODE *s=(SNODE*)malloc(sizeof(SNODE));
    s->ptr=node;
    s->next=head->next;
    head->next=s;
}
TNODE *popNRT(SNODE *head)
{
    SNODE *temp=head->next;
    TNODE *ptr=temp->ptr;
    head->next=temp->next;
    free(temp);
    return ptr;
}
int isEmptySNRT(SNODE *head)
{
    if(head->next==NULL)
        return 1;
    return 0;
}
void inOrderNRT(TNODE *node)
{
    if(node==NULL)
        return;
    //����ջ
    SNODE *head=initStackNRT();
    //����
    TNODE *p=node;
    while(!(isEmptySNRT(head))||p){
        if(p){
            pushNRT(head,p);
            p=p->left;
        }
        else{
            p=popNRT(head);
            printf("%d ",p->data);
            p=p->right;
        }
    }
}
void preOrderNRT(TNODE *node)
{
    if(node==NULL)
        return;
    SNODE *head=initStackNRT();
    TNODE *p=node;
    while(!(isEmptySNRT(head))||p){
        if(p){
            printf("%d ",p->data);
            pushNRT(head,p);
            p=p->left;
        }
        else{
            p=popNRT(head);
            p=p->right;
        }
    }
}
void postOrderNRT(TNODE *node)
{
    if(node==NULL)
        return;
    SNODE *head=initStackNRT();
    TNODE *ptrCurrent,*ptrLast;
    ptrCurrent=node;
    ptrLast=NULL;
    //��ptrCurrent���������������
    while(ptrCurrent){
        pushNRT(head,ptrCurrent);
        ptrCurrent=ptrCurrent->left;
    }
    while(!(isEmptySNRT(head))){
        ptrCurrent=popNRT(head);
        //һ�����ڵ㱻���ʵ�ǰ����:�����������������ѱ����ʹ�
        if(ptrCurrent->right==NULL||ptrCurrent->right==ptrLast){
            printf("%d ",ptrCurrent->data);
            //��ptrCurrent�ƶ���������һ�ڵ��������,ͨ���������
            ptrLast=ptrCurrent;
        }
        else{
            //����ǰ�ڵ㲻�ܱ�����,��ѹջ,����������,�ظ�ǰ�沿��
            pushNRT(head,ptrCurrent);
            ptrCurrent=ptrCurrent->right;
            while(ptrCurrent){
                pushNRT(head,ptrCurrent);
                ptrCurrent=ptrCurrent->left;
            }
        }
    }
}
void levelOrderNRT(TNODE *node)
{
    if(node==NULL)
        return;
    QNODE *head=initQueueNRT();
    TNODE *temp;
    int curLevel=1;//��ǰ��ʣ��δ���ʵĽڵ�
    int nextLevel=0;//��һ��δ���ʵĽڵ�
    enqueueNRT(head,node);
    while(!(isEmptyQNRT(head))){
        temp=dequeueNRT(head);
        printf("%d ",temp->data);
        curLevel--;
        if(temp->left){
            enqueueNRT(head,temp->left);
            nextLevel++;
        }
        if(temp->right){
            enqueueNRT(head,temp->right);
            nextLevel++;
        }
        if(curLevel==0){
            curLevel=nextLevel;
            nextLevel=0;
        }
    }
}
QNODE *initQueueNRT()
{
    QNODE *head=(QNODE*)malloc(sizeof(QNODE));
    head->next=NULL;
    return head;
}
void enqueueNRT(QNODE *head,TNODE *node)
{
    QNODE *s=(QNODE*)malloc(sizeof(QNODE));
    QNODE *cur=head;
    while(cur->next)
        cur=cur->next;
    s->ptr=node;
    cur->next=s;
    s->next=NULL;
}
TNODE *dequeueNRT(QNODE *head)
{
    QNODE *temp=head->next;
    TNODE *ptr=temp->ptr;
    head->next=temp->next;
    free(temp);
    return ptr;
}
int isEmptyQNRT(QNODE *head)
{
    if(head->next==NULL)
        return 1;
    return 0;
}
