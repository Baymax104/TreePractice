/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:51
*@Version
*/

#include "SuffixTree.h"
/*int main()
{
    char str[50];
    printf("请输入后缀表达式:\n");
    gets(str);
    SNODE *head=initStack();
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
            TNODE *sign=createTnode(str[i]);
            sign->right=pop(head);
            sign->left=pop(head);
            push(head,sign);
        }
            //处理数字节点
        else{
            TNODE *digit=createTnode(str[i]);
            push(head,digit);
        }
        i++;
    }
    TNODE *root=pop(head);
    printf("后序遍历结果如下:\n");
    postOrder(root);
    return 0;
}*/
SNODE *initStackST()
{
    SNODE *head=(SNODE*)malloc(sizeof(SNODE));
    head->next=NULL;
    return head;
}
void pushST(SNODE *head,TNODE *node)
{
    SNODE *s=(SNODE*)malloc(sizeof(SNODE));
    s->ptr=node;
    s->next=head->next;
    head->next=s;
}
TNODE *popST(SNODE *head)
{
    SNODE *temp=head->next;
    TNODE *ptr=temp->ptr;
    head->next=temp->next;
    free(temp);
    return ptr;
}
TNODE *createTnodeST(char ch)
{
    TNODE *t=(TNODE*)malloc(sizeof(TNODE));
    t->ch=ch;
    t->left=NULL;
    t->right=NULL;
    return t;
}
void postOrderST(TNODE *node)
{
    if(node){
        postOrderST(node->left);
        postOrderST(node->right);
        printf("%c ",node->ch);
    }
}
