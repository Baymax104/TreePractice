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
    printf("请按前序输入二叉树数据:(按-1结束当前节点子树输入)\n");
    createTree(&root);
    printf("前序遍历结果如下:\n");
    preOrder(root);
    printf("\n中序遍历结果如下:\n");
    inOrder(root);
    printf("\n后序遍历结果如下:\n");
    postOrder(root);
    printf("\n层次遍历结果如下:\n");
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
    //创建栈
    SNODE *head=initStackNRT();
    //遍历
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
    //将ptrCurrent移至左子树最左端
    while(ptrCurrent){
        pushNRT(head,ptrCurrent);
        ptrCurrent=ptrCurrent->left;
    }
    while(!(isEmptySNRT(head))){
        ptrCurrent=popNRT(head);
        //一个根节点被访问的前提是:无右子树或右子树已被访问过
        if(ptrCurrent->right==NULL||ptrCurrent->right==ptrLast){
            printf("%d ",ptrCurrent->data);
            //若ptrCurrent移动到了任意一节点的右子树,通过此语句标记
            ptrLast=ptrCurrent;
        }
        else{
            //若当前节点不能被访问,则压栈,移至右子树,重复前面部分
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
    int curLevel=1;//当前层剩余未访问的节点
    int nextLevel=0;//下一层未访问的节点
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
