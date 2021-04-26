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
            } else { // 单旋转
                zigSP(root, parent);
            }
        } else {
            if (grandparent) {
                if (grandparent->right == parent) { // RR
                    RRRotationSP(root, tnode);
                } else { // LR
                    LRRotationSP(root, tnode);
                }
            } else { // 单旋转
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
    printf("请输入数据:(按-1结束输入)\n");
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
    // 查找删除节点
    while (delNode->data != data) {
        if (data < delNode->data) {
            if (delNode->left) {
                delNode = delNode->left;
            } else {
                printf("不存在该数据!\n");
                return;
            }
        } else {
            if (delNode->right) {
                delNode = delNode->right;
            } else {
                printf("不存在该数据!\n");
                return;
            }
        }
    }
    // 将删除节点伸展到根节点
    splaySP(root, delNode);
    // 删除
    if (delNode->right) {
        Tnode *successor = delNode->right;
        // 查找中序后继节点
        while (successor->left) {
            successor = successor->left;
        }
        // 将中序后继节点伸展到根节点的右节点
        Tnode *parent;
        Tnode *grandparent;
        while ((*root)->right != successor) {
            parent = successor->parent;
            grandparent = parent->parent;
            if (parent->left == successor) {
                // 此处的特殊情况为grandparent为delNode时,只需单旋转即可
                if (grandparent && grandparent != delNode) {
                    if (grandparent->left == parent) { // LL
                        LLRotationSP(root, successor);
                    } else { // RL
                        RLRotationSP(root, successor);
                    }
                } else { // 单旋转
                    zigSP(root, parent);
                }
            } else {
                if (grandparent && grandparent != delNode) {
                    if (grandparent->right == parent) { // RR
                        RRRotationSP(root, successor);
                    } else { // LR
                        LRRotationSP(root, successor);
                    }
                } else { // 单旋转
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
        puts("1)添加节点");
        puts("2)删除节点");
        puts("3)前序遍历");
        puts("4)中序遍历");
        puts("5)后序遍历");
        puts("6)退出");
        puts("请输入你的选择:");
        scanf("%d", &op);
        switch (op) {
            case 1:
                puts("请输入添加的数据:");
                scanf("%d", &data);
                insertSP(&root, data);
                break;
            case 2:
                puts("请输入删除的数据:");
                scanf("%d", &delData);
                delSP(&root, delData);
                break;
            case 3:
                printf("前序遍历:");
                preOrderSP(root);
                printf("\n");
                break;
            case 4:
                printf("中序遍历:");
                inOrderSP(root);
                printf("\n");
                break;
            case 5:
                printf("后序遍历:");
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
