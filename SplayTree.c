/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 22:59
*@Version
*/

#include "SplayTree.h"
/*int main () {
    Tnode *root = NULL;
    createTreeSP(&root);
    projectSP(root);
    return 0;
}*/
void preOrderSP(Tnode *tnode) {
    if (tnode) {
        printf("%d ", tnode->data);
        preOrderSP(tnode->left);
        preOrderSP(tnode->right);
    }
}
void inOrderSP(Tnode *tnode) {
    if (tnode) {
        inOrderSP(tnode->left);
        printf("%d ", tnode->data);
        inOrderSP(tnode->right);
    }
}
void postOrderSP(Tnode *tnode) {
    if (tnode) {
        postOrderSP(tnode->left);
        postOrderSP(tnode->right);
        printf("%d ", tnode->data);
    }
}
void zigSP(Tnode **root, Tnode *tnode) {
    Tnode *temp = tnode->left;
    if (temp) {
        Tnode *parent = tnode->parent;
        tnode->left = temp->right;
        if (temp->right) {
            temp->right->parent = tnode;
        }
        temp->parent = parent;
        if (parent) {
            if (parent->left == tnode) {
                parent->left = temp;
            } else {
                parent->right = temp;
            }
        } else {
            *root = temp;
        }
        tnode->parent = temp;
        temp->right = tnode;
    }
}
void zagSP(Tnode **root, Tnode *tnode) {
    Tnode *temp = tnode->right;
    if (temp) {
        Tnode *parent = tnode->parent;
        tnode->right = temp->left;
        if (temp->left) {
            temp->left->parent = tnode;
        }
        temp->parent = parent;
        if (parent) {
            if (parent->left == tnode) {
                parent->left = temp;
            } else {
                parent->right = temp;
            }
        } else {
            *root = temp;
        }
        tnode->parent = temp;
        temp->left = tnode;
    }
}
void LLRotationSP(Tnode **root, Tnode *tnode) {
    Tnode *parent = tnode->parent;
    Tnode *grandparent = parent->parent;
    zigSP(root, grandparent);
    zigSP(root, parent);
}
void RRRotationSP(Tnode **root, Tnode *tnode) {
    Tnode *parent = tnode->parent;
    Tnode *grandparent = parent->parent;
    zagSP(root, grandparent);
    zagSP(root, parent);
}
void RLRotationSP(Tnode **root, Tnode *tnode) {
    Tnode *parent = tnode->parent;
    Tnode *grandparent = parent->parent;
    zigSP(root, parent);
    zagSP(root, grandparent);
}
void LRRotationSP(Tnode **root, Tnode *tnode) {
    Tnode *parent = tnode->parent;
    Tnode *grandparent = parent->parent;
    zagSP(root, parent);
    zigSP(root, grandparent);
}
void splaySP(Tnode **root, Tnode *tnode) {
    Tnode *parent;
    Tnode *grandparent;
    while (*root != tnode) {
        parent = tnode->parent;
        grandparent = parent->parent;
        if (parent->left == tnode) {
            if (grandparent) {
                if (grandparent->left == parent) { // LL
                    LLRotationSP(root, tnode);
                } else { // RL
                    RLRotationSP(root, tnode);
                }
            } else { // ����ת
                zigSP(root, parent);
            }
        } else {
            if (grandparent) {
                if (grandparent->right == parent) { // RR
                    RRRotationSP(root, tnode);
                } else { // LR
                    LRRotationSP(root, tnode);
                }
            } else { // ����ת
                zagSP(root, parent);
            }
        }
    }
}
void insertSP(Tnode **root, int data) {
    Tnode *temp;
    initNodeSP(&temp);
    temp->data = data;
    Tnode *current = *root;
    Tnode *parent = NULL;
    while (current) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    temp->parent = parent;
    if (parent) {
        if (data < parent->data) {
            parent->left = temp;
        } else {
            parent->right = temp;
        }
    } else {
        *root = temp;
    }
    splaySP(root, temp);
}
void initNodeSP(Tnode **temp) {
    *temp = (Tnode*)malloc(sizeof (Tnode));
    (*temp)->data = 0;
    (*temp)->parent = NULL;
    (*temp)->left = NULL;
    (*temp)->right = NULL;
}
void createTreeSP(Tnode **root) {
    int data;
    printf("����������:(��-1��������)\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        insertSP(root, data);
    }
}
void delSP(Tnode **root, int data) {
    Tnode *delNode = *root;
    // ����ɾ���ڵ�
    while (delNode->data != data) {
        if (data < delNode->data) {
            if (delNode->left) {
                delNode = delNode->left;
            } else {
                printf("�����ڸ�����!\n");
                return;
            }
        } else {
            if (delNode->right) {
                delNode = delNode->right;
            } else {
                printf("�����ڸ�����!\n");
                return;
            }
        }
    }
    // ��ɾ���ڵ���չ�����ڵ�
    splaySP(root, delNode);
    // ɾ��
    if (delNode->right) {
        Tnode *successor = delNode->right;
        // ���������̽ڵ�
        while (successor->left) {
            successor = successor->left;
        }
        // �������̽ڵ���չ�����ڵ���ҽڵ�
        Tnode *parent;
        Tnode *grandparent;
        while ((*root)->right != successor) {
            parent = successor->parent;
            grandparent = parent->parent;
            if (parent->left == successor) {
                // �˴����������ΪgrandparentΪdelNodeʱ,ֻ�赥��ת����
                if (grandparent && grandparent != delNode) {
                    if (grandparent->left == parent) { // LL
                        LLRotationSP(root, successor);
                    } else { // RL
                        RLRotationSP(root, successor);
                    }
                } else { // ����ת
                    zigSP(root, parent);
                }
            } else {
                if (grandparent && grandparent != delNode) {
                    if (grandparent->right == parent) { // RR
                        RRRotationSP(root, successor);
                    } else { // LR
                        LRRotationSP(root, successor);
                    }
                } else { // ����ת
                    zagSP(root, parent);
                }
            }
        }
        successor->left = delNode->left;
        delNode->left->parent = successor;
        successor->parent = NULL;
        *root = successor;
        free(delNode);
    } else {
        *root = delNode->left;
        if (*root) {
            (*root)->parent = NULL;
        }
        free(delNode);
    }
}
void projectSP(Tnode *root) {
    int op;
    int data;
    int delData;
    do {
        puts("1)��ӽڵ�");
        puts("2)ɾ���ڵ�");
        puts("3)ǰ�����");
        puts("4)�������");
        puts("5)�������");
        puts("6)�˳�");
        puts("���������ѡ��:");
        scanf("%d", &op);
        switch (op) {
            case 1:
                puts("��������ӵ�����:");
                scanf("%d", &data);
                insertSP(&root, data);
                break;
            case 2:
                puts("������ɾ��������:");
                scanf("%d", &delData);
                delSP(&root, delData);
                break;
            case 3:
                printf("ǰ�����:");
                preOrderSP(root);
                printf("\n");
                break;
            case 4:
                printf("�������:");
                inOrderSP(root);
                printf("\n");
                break;
            case 5:
                printf("�������:");
                postOrderSP(root);
                printf("\n");
                break;
            case 6:
                puts("Goodbye");
                return;
            default:
                break;
        }
    } while (1);
}
