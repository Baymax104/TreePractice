/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:44
*@Version
*/

#include "ChildAndSibling.h"
/*int main()
{
    Tree tree;
    Tree *ptrTree=&tree;
    createTree(ptrTree);
    project(ptrTree);
}*/
void createTreeCS(Tree *ptrTree)
{
    int data;
    initTreeCS(ptrTree);
    printf("请输入根节点数据:\n");
    scanf("%d",&data);
    addTreeCS(data,-1,ptrTree);
}
void initTreeCS(Tree *ptrTree)
{
    ptrTree->cnt=-1;
    int i;
    for(i=0;i<MAX;i++){
        ptrTree->node[i].firstChild=-1;
        ptrTree->node[i].nextSibling=-1;
    }
}
void addTreeCS(int data,int parent,Tree *ptrTree)
{
    ptrTree->cnt++;
    ptrTree->node[ptrTree->cnt].data=data;
    if(parent==-1){
        return;
    }
    else{
        if(ptrTree->node[parent].firstChild==-1)
            ptrTree->node[parent].firstChild=ptrTree->cnt;
        else{
            int current=ptrTree->node[parent].firstChild;
            while(ptrTree->node[current].nextSibling!=-1)
                current=ptrTree->node[current].nextSibling;
            ptrTree->node[current].nextSibling=ptrTree->cnt;
        }
    }
}
void preOrderCS(Tree *ptrTree,int root)
{
    if(root!=-1){
        printf("%d,%d,%d\n",ptrTree->node[root].data,ptrTree->node[root].firstChild,ptrTree->node[root].nextSibling);
        preOrderCS(ptrTree,ptrTree->node[root].firstChild);
        preOrderCS(ptrTree,ptrTree->node[root].nextSibling);
    }
}
void postOrderCS(Tree *ptrTree,int root)
{
    if(root!=-1){
        postOrderCS(ptrTree,ptrTree->node[root].firstChild);
        postOrderCS(ptrTree,ptrTree->node[root].nextSibling);
        printf("%d,%d,%d\n",ptrTree->node[root].data,ptrTree->node[root].firstChild,ptrTree->node[root].nextSibling);
    }
}
void projectCS(Tree *ptrTree)
{
    int op;
    int data;
    int parent;
    int delIndex;
    do{
        printf("1)添加节点\n");
        printf("2)先序遍历\n");
        printf("3)后序遍历\n");
        printf("4)删除节点\n");
        printf("5)退出\n");
        printf("请输入你的选择:\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("请输入节点数据及双亲:(a,b)\n");
                scanf("%d,%d",&data,&parent);
                addTreeCS(data,parent,ptrTree);
                break;
            case 2:
                printf("先序遍历结果如下:\n");
                preOrderCS(ptrTree,0);
                break;
            case 3:
                printf("后序遍历结果如下:\n");
                postOrderCS(ptrTree,0);
                break;
            case 4:
                printf("请输入需要删除的节点:\n");
                scanf("%d",&delIndex);
                delTreeCS(ptrTree,delIndex);
                break;
            case 5:
                printf("Goodbye\n");
                return;
            default:
                break;
        }
    }while(1);
}
void delTreeCS(Tree *ptrTree,int index)
{
    int i;
    if(ptrTree->node[index].firstChild==-1&&ptrTree->node[index].nextSibling==-1){
        for(i=0;i<=ptrTree->cnt;i++){
            if(ptrTree->node[i].firstChild==index)
                ptrTree->node[i].firstChild=-1;
            else if(ptrTree->node[i].nextSibling==index)
                ptrTree->node[i].nextSibling=-1;
        }
    }
    else if(ptrTree->node[index].firstChild!=-1&&ptrTree->node[index].nextSibling==-1){
        for(i=0;i<=ptrTree->cnt;i++){
            if(ptrTree->node[i].firstChild==index){
                ptrTree->node[i].firstChild=ptrTree->node[index].firstChild;
                ptrTree->node[index].firstChild=-1;
            }
            else if(ptrTree->node[i].nextSibling==index){
                ptrTree->node[i].nextSibling=ptrTree->node[index].firstChild;
                ptrTree->node[index].firstChild=-1;
            }
        }
    }
    else if(ptrTree->node[index].firstChild==-1&&ptrTree->node[index].nextSibling!=-1){
        for(i=0;i<=ptrTree->cnt;i++){
            if(ptrTree->node[i].firstChild==index){
                ptrTree->node[i].firstChild=ptrTree->node[index].nextSibling;
                ptrTree->node[index].nextSibling=-1;
            }
            else if(ptrTree->node[i].nextSibling==index){
                ptrTree->node[i].nextSibling=ptrTree->node[index].nextSibling;
                ptrTree->node[index].nextSibling=-1;
            }
        }
    }
    else{
        for(i=0;i<=ptrTree->cnt;i++){
            if(ptrTree->node[i].firstChild==index){
                ptrTree->node[i].firstChild=-1;
                ptrTree->node[index].firstChild=-1;
                ptrTree->node[index].nextSibling=-1;
            }
            else if(ptrTree->node[i].nextSibling==index){
                ptrTree->node[i].nextSibling=-1;
                ptrTree->node[index].firstChild=-1;
                ptrTree->node[index].nextSibling=-1;
            }
        }
    }
}
