/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 22:46
*@Version
*/

#include "AVLTree.h"
/*int main () {
    Tnode *root = NULL;
    createTree(&root);
    project(root);
    return 0;
}*/
int getHeightAVL(Tnode *node) {
    if (node) {
        return node->height;
    }
    return -1;
}
void initTnodeAVL(Tnode **node) {
    *node = (Tnode *)malloc(sizeof (Tnode));
    (*node)->data = 0;
    (*node)->height = 0;
    (*node)->left = NULL;
    (*node)->right = NULL;
}
void singleLeftRotationAVL(Tnode **node) {
    Tnode *temp = (*node)->left;
    (*node)->left = temp->right;
    temp->right = *node;
    (*node)->height = MAX(getHeightAVL((*node)->right),
                          getHeightAVL((*node)->left)) + 1;
    temp->height = MAX(getHeightAVL((*node)->left),
                       (*node)->height) + 1;
    *node = temp;// 改变根节点
}
void singleRightRotationAVL(Tnode **node) {
    Tnode *temp = (*node)->right;
    (*node)->right = temp->left;
    temp->left = *node;
    (*node)->height = MAX(getHeightAVL((*node)->left),
                          getHeightAVL((*node)->right)) + 1;
    temp->height = MAX(getHeightAVL((*node)->right),
                       (*node)->height) + 1;
    *node = temp;// 改变根节点
}
void doubleLeftRotationAVL(Tnode **node) {
    singleRightRotationAVL(&(*node)->left);
    singleLeftRotationAVL(node);
}
void doubleRightRotationAVL(Tnode **node) {
    singleLeftRotationAVL(&(*node)->right);
    singleRightRotationAVL(node);
}
void insertAVL(Tnode **node, int data) {
    Tnode *temp = NULL;
    if ((*node) == NULL) {
        initTnodeAVL(&temp);
        temp->data = data;
        *node = temp;
        return;
    }
    if (data < (*node)->data) {
        insertAVL(&(*node)->left, data);
        if (2 == getHeightAVL((*node)->left) - getHeightAVL((*node)->right)) {
            if (data < (*node)->left->data) {
                // 插入点在左子树的左子树(LL),右旋
                singleLeftRotationAVL(node);
            } else {
                // 插入点在左子树的右子树(LR)
                doubleLeftRotationAVL(node);
            }
        }
    } else {
        insertAVL(&(*node)->right, data);
        if (2 == getHeightAVL((*node)->right) - getHeightAVL((*node)->left)) {
            if (data > (*node)->right->data) {
                // 插入点在右子树的右子树(RR),左旋
                singleRightRotationAVL(node);
            } else {
                // 插入点在右子树的左子树(RL)
                doubleRightRotationAVL(node);
            }
        }
    }
    (*node)->height = MAX(getHeightAVL((*node)->right),
                          getHeightAVL((*node)->left)) + 1;
}
void createTreeAVL(Tnode **node) {
    int data;
    printf("请输入数据:(按-1结束输入)\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        insertAVL(node, data);
    }
}
void delNodeAVL(Tnode **node, int data) {
    if (*node == NULL) {
        return;
    }
    if (data < (*node)->data) {
        delNodeAVL(&(*node)->left, data);
        if (getHeightAVL((*node)->right) - getHeightAVL((*node)->left) == 2) {
            Tnode *right = (*node)->right;
            if (right->left &&
                getHeightAVL(right->left) > getHeightAVL(right->right)) {
                doubleRightRotationAVL(node);
            } else {
                singleRightRotationAVL(node);
            }
        }
    } else if (data > (*node)->data) {
        delNodeAVL(&(*node)->right, data);
        if (getHeightAVL((*node)->left) - getHeightAVL((*node)->right) == 2) {
            Tnode *left = (*node)->left;
            if (left->right &&
                getHeightAVL(left->right) > getHeightAVL(left->left)) {
                doubleLeftRotationAVL(node);
            } else {
                singleLeftRotationAVL(node);
            }
        }
    } else {
        if ((*node)->left && (*node)->right) {
            // 处理分支节点
            Tnode *temp = (*node)->right;
            while (temp->left) {
                temp = temp->left;
            }
            (*node)->data = temp->data;
            delNodeAVL(&(*node)->right, temp->data);// 删除右子树最小节点
            // 删除该节点后必定左子树高度 > 右子树高度
            // 若删除后右子树高度 > 左子树高度，则在删除前就不平衡
            if (getHeightAVL((*node)->left) - getHeightAVL((*node)->right) == 2) {
                if ((*node)->left->right &&
                    getHeightAVL((*node)->left->right) > getHeightAVL((*node)->left->left)) {
                    doubleLeftRotationAVL(node);
                } else {
                    singleLeftRotationAVL(node);
                }
            }
        } else {
            if ((*node)->left == NULL && (*node)->right) {
                *node = (*node)->right;
            } else if ((*node)->right == NULL && (*node)->left) {
                *node = (*node)->left;
            } else {
                Tnode **temp = node;// 需要修改*node的值而不能直接修改，使用**temp进行修改
                free(*temp);
                *temp = NULL;
            }
        }
    }
    if (*node) {
        (*node)->height = MAX(getHeightAVL((*node)->left),
                              getHeightAVL((*node)->right)) + 1;
    }
}
void preOrderAVL(Tnode *node) {
    if (node) {
        printf("%d ", node->data);
        preOrderAVL(node->left);
        preOrderAVL(node->right);
    }
}
void inOrderAVL(Tnode *node) {
    if (node) {
        inOrderAVL(node->left);
        printf("%d ", node->data);
        inOrderAVL(node->right);
    }
}
void postOrderAVL(Tnode *node) {
    if (node) {
        postOrderAVL(node->left);
        postOrderAVL(node->right);
        printf("%d ", node->data);
    }
}
void projectAVL(Tnode *node) {
    int op;
    int insertData;
    int delData;
    do {
        printf("1)添加节点\n");
        printf("2)删除节点\n");
        printf("3)前序遍历\n");
        printf("4)中序遍历\n");
        printf("5)后序遍历\n");
        printf("6)退出\n");
        printf("请输入你的选择:\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("请输入要插入的数据:\n");
                scanf("%d", &insertData);
                insertAVL(&node, insertData);
                break;
            case 2:
                printf("请输入要删除的数据:\n");
                scanf("%d", &delData);
                delNodeAVL(&node, delData);
                break;
            case 3:
                printf("前序遍历:");
                preOrderAVL(node);
                printf("\n");
                break;
            case 4:
                printf("中序遍历:");
                inOrderAVL(node);
                printf("\n");
                break;
            case 5:
                printf("后序遍历:");
                postOrderAVL(node);
                printf("\n");
                break;
            case 6:
                printf("Goodbye\n");
                return;
            default:
                break;
        }
    } while (1);
}
