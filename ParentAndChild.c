/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:42
*@Version
*/

#include "ParentAndChild.h"
/*int main()
{
    Tree tree;
    Tree *ptrTree=&tree;
    createTree(ptrTree);
    project(ptrTree);
}*/
void initTreePC(Tree *ptrTree)
{
    ptrTree->cnt=-1;
    int i;
    for(i=0;i<MAX;i++){
        ptrTree->node[i].firstChild=(Node*)malloc(sizeof(Node));
        ptrTree->node[i].firstChild->next=NULL;
        ptrTree->node[i].parent=-1;
    }
}
void addTreePC(int data,int parent,Tree *ptrTree)
{
    ptrTree->cnt++;
    ptrTree->node[ptrTree->cnt].data=data;
    ptrTree->node[ptrTree->cnt].parent=parent;
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->childIndex=ptrTree->cnt;
    temp->next=NULL;
    if(parent>=0){
        if(ptrTree->node[parent].firstChild->next == NULL){
            ptrTree->node[parent].firstChild->next=temp;
        }
        else{
            Node *pre=ptrTree->node[parent].firstChild->next;
            while(pre->next)
                pre=pre->next;
            pre->next=temp;
        }
    }
}
void createTreePC(Tree *ptrTree)
{
    int data;
    initTreePC(ptrTree);
    printf("��������ڵ�����:\n");
    scanf("%d",&data);
    addTreePC(data,-1,ptrTree);
}
void preOrderPC(Tree *ptrTree,int root)//�������
{
    int current;
    if(ptrTree->cnt!=-1){
        printf("%d,%d\n",ptrTree->node[root].data,ptrTree->node[root].parent);
        for(current=0;current<=ptrTree->cnt;current++){
            if(ptrTree->node[current].parent==root){
                preOrderPC(ptrTree,current);
            }
        }
    }
}
void postOrderPC(Tree *ptrTree,int root)//�������
{
    int current;
    if(ptrTree->cnt!=0){
        for(current=0;current<=ptrTree->cnt;current++){
            if(ptrTree->node[current].parent==root)
                postOrderPC(ptrTree,current);
        }
        printf("%d,%d\n",ptrTree->node[root].data,ptrTree->node[root].parent);
    }
}
void projectPC(Tree *ptrTree)
{
    int op;
    int data;
    int parent;
    int delIndex;
    do{
        printf("1)��ӡ��\n");
        printf("2)��ӽڵ�\n");
        printf("3)�������\n");
        printf("4)�������\n");
        printf("5)ɾ���ڵ�\n");
        printf("6)�˳�\n");
        printf("���������ѡ��:\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                printTreePC(ptrTree);
                break;
            case 2:
                printf("������ڵ�����ݺ�˫��:(a,b)\n");
                scanf("%d,%d",&data,&parent);
                addTreePC(data,parent,ptrTree);
                break;
            case 3:
                printf("��������������:\n");
                preOrderPC(ptrTree,0);
                break;
            case 4:
                printf("��������������:\n");
                postOrderPC(ptrTree,0);
                break;
            case 5:
                printf("��������Ҫɾ���Ľڵ�:\n");
                scanf("%d",&delIndex);
                delTreePC(ptrTree,delIndex);
                break;
            case 6:
                printf("Goodbye\n");
                return;
            default:
                break;
        }
    }while(1);
}
void printTreePC(Tree *ptrTree)
{
    int i;
    for(i=0;i<=ptrTree->cnt;i++){
        if(ptrTree->node[i].parent==-1&&i!=0)
            continue;
        else{
            printf("%d,%d ",ptrTree->node[i].data,ptrTree->node[i].parent);
            Node *temp=ptrTree->node[i].firstChild;
            while(temp->next){
                temp=temp->next;
                printf("%d ",temp->childIndex);
            }
            printf("\n");
        }
    }
}
void delTreePC(Tree *ptrTree,int index)
{
    int i;
    Node *preTemp=ptrTree->node[ptrTree->node[index].parent].firstChild;
    Node *temp=ptrTree->node[ptrTree->node[index].parent].firstChild->next;
    while(temp){
        if(temp->childIndex==index)
            break;
        temp=temp->next;
        preTemp=preTemp->next;
    }
    Node *tempS=temp;
    for(i=0;i<=ptrTree->cnt;i++){
        if(ptrTree->node[i].parent==index){//�ж�index�Ƿ��к���
            ptrTree->node[i].parent=ptrTree->node[index].parent;
            Node *s=(Node*)malloc(sizeof(Node));
            s->childIndex=i;
            s->next=temp->next;
            temp->next=s;
            temp=temp->next;
        }
    }
    temp=tempS;
    //ɾ���ڵ�
    preTemp->next=temp->next;
    free(temp);
    ptrTree->node[index].parent=-1;
}
