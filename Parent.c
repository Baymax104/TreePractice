/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:40
*@Version
*/

#include "Parent.h"
/*int main()
{
    Tree tree;
    Tree *ptrTree=&tree;
    createTree(ptrTree);
    project(ptrTree);
    return 0;
}*/
void initTreeP(Tree *ptrTree)
{
    ptrTree->cnt=-1;
    int i;
    for(i=0;i<MAX;i++){
        ptrTree->nodes[i].parent=-1;
    }
}
void addTreeP(int data,int parent,Tree *ptrTree)
{
    ptrTree->cnt++;
    ptrTree->nodes[ptrTree->cnt].data=data;
    ptrTree->nodes[ptrTree->cnt].parent=parent;
}
void createTreeP(Tree *ptrTree)
{
    int data;
    initTreeP(ptrTree);
    printf("��������ڵ�����:\n");
    scanf("%d",&data);
    addTreeP(data,-1,ptrTree);
}
void preOrderP(Tree *ptrTree,int root)//ǰ�����
{
    int current;
    if(ptrTree->cnt!=-1){
        printf("%d,%d\n",ptrTree->nodes[root].data,ptrTree->nodes[root].parent);
        for(current=0;current<=ptrTree->cnt;current++){
            if(ptrTree->nodes[current].parent==root){
                preOrderP(ptrTree,current);
            }
        }
    }
}
void postOrderP(Tree *ptrTree,int root)//�������
{
    int current;
    if(ptrTree->cnt!=-1){
        for(current=0;current<=ptrTree->cnt;current++){
            if(ptrTree->nodes[current].parent==root)
                postOrderP(ptrTree,current);
        }
        printf("%d,%d\n",ptrTree->nodes[root].data,ptrTree->nodes[root].parent);
    }
}
void projectP(Tree *ptrTree)
{
    int op;
    int data;
    int parent;
    int delIndex;
    do{
        printf("1)��ӽڵ�\n");
        printf("2)ǰ�����\n");
        printf("3)�������\n");
        printf("4)ɾ���ڵ�\n");
        printf("5)�˳�\n");
        printf("���������ѡ��:\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("������ڵ�����ݺ�˫���±�:(a,b)\n");
                scanf("%d,%d",&data,&parent);
                addTreeP(data,parent,ptrTree);
                break;
            case 2:
                printf("��������������:\n");
                preOrderP(ptrTree,0);
                break;
            case 3:
                printf("��������������:\n");
                postOrderP(ptrTree,0);
                break;
            case 4:
                printf("��������Ҫɾ���Ľڵ��±�:\n");
                scanf("%d",&delIndex);
                delTreeP(ptrTree,delIndex);
                break;
            case 5:
                printf("Goodbye\n");
                return;
            default:
                break;
        }
    }while(1);
}
void delTreeP(Tree *ptrTree,int index)
{
    int i;
    for(i=0;i<=ptrTree->cnt;i++){
        if(ptrTree->nodes[i].parent==index)
            ptrTree->nodes[i].parent=ptrTree->nodes[index].parent;
    }
    ptrTree->nodes[index].parent=-1;
    ptrTree->cnt--;
}
