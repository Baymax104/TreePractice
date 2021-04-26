/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 22:53
*@Version
*/

#include "RedBlackTree.h"
/*int main () {
    Tnode *root = NULL;
    createTreeRBT(&root);
    projectRBT(root);
    return 0;
}*/
void preOrderRBT(Tnode *tnode) {
    if (tnode) {
        printf("%d ", tnode->data);
        preOrderRBT(tnode->left);
        preOrderRBT(tnode->right);
    }
}
void inOrderRBT(Tnode *tnode) {
    if (tnode) {
        inOrderRBT(tnode->left);
        printf("%d ", tnode->data);
        inOrderRBT(tnode->right);
    }
}
void postOrderRBT(Tnode *tnode) {
    if (tnode) {
        postOrderRBT(tnode->left);
        postOrderRBT(tnode->right);
        printf("%d ", tnode->data);
    }
}
void insertRBT(Tnode **root, int data) {
    Tnode *temp;
    initNodeRBT(&temp);
    temp->data = data;
    Tnode *current = *root;
    Tnode *parent = NULL;
    // 获取插入节点的父节点
    while (current) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    // 插入
    temp->parent = parent;
    if (parent) {
        if (data < parent->data) {
            parent->left = temp;
        } else {
            parent->right = temp;
        }
    } else {
        // 若parent为空，则插入节点为根节点
        *root = temp;
    }
    // 修正函数
    updateIRBT(root, &temp);
}
void initNodeRBT(Tnode **tnode) {
    *tnode = (Tnode*)malloc(sizeof (Tnode));
    (*tnode)->left = NULL;
    (*tnode)->right = NULL;
    (*tnode)->parent = NULL;
    (*tnode)->color = RED;
    (*tnode)->data = 0;
}
void RRRotationRBT(Tnode **root, Tnode *tnode) {
    Tnode *temp = tnode->right;
    if (temp) {
        tnode->right = temp->left;
        if (temp->left) {
            temp->left->parent = tnode;
        }
        temp->parent = tnode->parent;
        if (!tnode->parent) {
            *root = temp;
        } else {
            if (tnode->parent->left == tnode) {
                tnode->parent->left = temp;
            } else {
                tnode->parent->right = temp;
            }
        }
        temp->left = tnode;
        tnode->parent = temp;
    }
}
void LLRotationRBT(Tnode **root, Tnode *tnode) {
    Tnode *temp = tnode->left;
    if (temp) {
        tnode->left = temp->right;
        if (temp->right) {
            temp->right->parent = tnode;
        }
        temp->parent = tnode->parent;
        if (!tnode->parent) {
            *root = temp;
        } else {
            if (tnode->parent->right == tnode) {
                tnode->parent->right = temp;
            } else {
                tnode->parent->left = temp;
            }
        }
        temp->right = tnode;
        tnode->parent = temp;
    }
}
void updateIRBT(Tnode **root, Tnode **node) {
    Tnode *parent, *grandparent;
    // 若parent为空,则node为根节点
    // 若parent为黑色,则不需要调整
    while ((parent = (*node)->parent) && parent->color == RED) {
        grandparent = parent->parent;
        // 左右镜像调整
        // 若parent为grandparent的左节点
        if (parent == grandparent->left) {
            Tnode *uncle = grandparent->right;
            // 若uncle为红色
            if (uncle && uncle->color == RED) {
                uncle->color = BLACK;
                parent->color = BLACK;
                grandparent->color = RED;
                // 通过重新设置node,通过node获取parent和grandparent来向上回溯
                *node = grandparent;
                continue;
            }
            // 若uncle为黑色(包含uncle为空的情况)
            // 插入节点为parent的右节点(此时情况为LR)
            if (parent->right == *node) {
                RRRotationRBT(root, parent);
                // 旋转时不会改变parent和node,只会改变位置，旋转后parent为node的左节点
                // 交换parent和node
                Tnode *temp = parent;
                parent = *node;
                *node = temp;
            }
            parent->color = BLACK;
            grandparent->color = RED;
            LLRotationRBT(root, grandparent);
        } else {
            // 若parent为grandparent的右节点
            Tnode *uncle = grandparent->left;
            // 若uncle为红色
            if (uncle && uncle->color == RED) {
                uncle->color = BLACK;
                parent->color = BLACK;
                grandparent->color = RED;
                *node = grandparent;
                continue;
            }
            // 若uncle为黑色
            // 插入点parent的左节点(此时情况为RL)
            if (parent->left == *node) {
                LLRotationRBT(root, parent);
                Tnode *temp = parent;
                parent = *node;
                *node = temp;
            }
            parent->color = BLACK;
            grandparent->color = RED;
            RRRotationRBT(root, grandparent);
        }
    }
    (*root)->color = BLACK;
}
void createTreeRBT(Tnode **root) {
    int data;
    printf("请输入数据:(按-1结束输入)\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        insertRBT(root, data);
    }
}
void delRBT(Tnode **root, int data) {
    Tnode *delNode = *root;
    Tnode *child = NULL;
    Tnode *parent = NULL;
    // 获取删除节点
    while (delNode->data != data) {
        if (data < delNode->data) {
            if (delNode->left) {
                delNode = delNode->left;
            } // 此处检查data是否存在于树中
        } else if (data > delNode->data) {
            if (delNode->right) {
                delNode = delNode->right;
            } // 此处检查data是否存在于树中
        }
    }
    // 删除
    if (!delNode->left && !delNode->right) { // 若delNode的左右节点都为空
        parent = delNode->parent;
        if (delNode == *root) {
            *root = NULL;
        } else if (parent->left == delNode) { // 若delNode为parent的左节点
            parent->left = NULL;
        } else if (parent->right == delNode) { // 若delNode为parent的右节点
            parent->right = NULL;
        }
    } else if (!delNode->left && delNode->right) { // 若delNode的左节点为空,右节点不为空
        child = delNode->right;
        parent = delNode->parent;
        if (delNode == *root) {
            *root = child;
            child->parent = NULL;
        }
        else if (parent->left == delNode) { // 若delNode为parent的左节点
            parent->left = child;
            child->parent = parent;
        } else if (parent->right == delNode) { // 若delNode为parent的右节点
            parent->right = child;
            child->parent = parent;
        }
    } else if (delNode->left && !delNode->right) { // 若delNode的左节点不为空,右节点为空
        child = delNode->left;
        parent = delNode->parent;
        if (delNode == *root) {
            *root = child;
            child->parent = NULL;
        }
        else if (parent->left == delNode) {
            parent->left = child;
            child->parent = parent;
        } else if (parent->right == delNode) {
            parent->right = child;
            child->parent = parent;
        }
    } else { // 若delNode的左右节点都不为空
        // 获取中序后继节点
        Tnode *successor = delNode->right;
        while (successor->left) {
            successor = successor->left;
        }
        // 用successor(中序后继节点)来替换
        // 若delNode->parent不为空，则delNode不是根节点
        if (delNode->parent) {
            // 将delNode的parent连接到successor
            if (delNode->parent->left == delNode) {
                delNode->parent->left = successor;
            } else {
                delNode->parent->right = successor;
            }
        } else { // 若delNode为根节点
            *root = successor;
        }

        // 对successor的parent和child的处理
        // 以下对child的处理分为两种情况:
        // 当delNode为successor的右节点时,不需要处理child,只需将delNode替换为successor
        // 当delNode不为successor的右节点时,需要处理child,将child和successor的parent连接

        // successor一定没有左节点
        child = successor->right;
        parent = successor->parent;
        int color = successor->color;
        // 若successor为delNode的右节点
        if (parent == delNode) {
            parent = successor;
        } else { // 若successor不为delNode的右节点
            if (child) {
                child->parent = parent;
            }
            parent->left = child;
            // 对delNode右节点的处理
            successor->right = delNode->right;
            delNode->right->parent = successor;
        }
        // 替换delNode和successor
        successor->parent = delNode->parent;
        successor->left = delNode->left;
        delNode->left->parent = successor;
        successor->color = delNode->color;
        // 修正函数
        // 若delNode为红色,则不需要调整
        if (color == BLACK) {
            // child以下均满足性质,从child开始调整
            updateDRBT(root, child, parent);
        }
        return;
    }
    // 修正函数
    // 若delNode为红色,则不需要调整
    if (delNode->color == BLACK) {
        // child以下均满足性质,从child开始调整
        updateDRBT(root, child, parent);
    }
}
// child为待修正的点
void updateDRBT(Tnode **root, Tnode *child, Tnode *parent) {
    Tnode *sibling;
    // 若child为黑色或空节点
    // 有五种情况需要调整:
    // 1.sibling为红色,左右节点为黑色
    // 转化为情况2
    // 2.sibling为黑色,左右节点为空
    // 将sibling变为红色,之后向上回溯,直到跳出循环
    // 3.sibling为黑色,左节点为红色
    // 转化为情况4
    // 4.sibling为黑色,右节点为红色
    // 5.sibling为黑色,左右节点为红色
    // sibling的颜色变为parent的颜色,parent变黑,sibling右节点变黑,将parent左旋,child设为root

    // 若child为根节点,因为child以下均满足性质,所以不需要调整
    while ((!child || child->color == BLACK) && child != *root) {
        // 左右镜像调整
        if (parent->left == child) {
            sibling = parent->right;
            // 情况1转化为情况2
            if (sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                RRRotationRBT(root, parent);
                sibling = parent->right;
            }
            // 处理情况2
            if ((!sibling->left || sibling->left->color == BLACK) &&
                (!sibling->right || sibling->right->color == BLACK)) {
                sibling->color = RED;
                // 向上回溯
                child = parent;
                parent = child->parent;
            } else { // 处理情况3,4,5
                // 将情况3转化为情况4
                if (!sibling->right || sibling->right->color == BLACK) {
                    sibling->left->color = BLACK;
                    sibling->color = RED;
                    LLRotationRBT(root, sibling);
                    sibling = parent->right;
                }
                // 处理情况4,5
                // 处理步骤相同,最终状态不同,均满足性质
                sibling->color = parent->color;
                parent->color = BLACK;
                sibling->right->color = BLACK;
                RRRotationRBT(root, parent);
                child = *root;
                break;
            }
        } else { // 镜像调整,同理
            sibling = parent->left;
            if (sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                LLRotationRBT(root, parent);
                sibling = parent->left;
            }
            if ((!sibling->left || sibling->left->color == BLACK) &&
                (!sibling->right || sibling->right->color == BLACK)) {
                sibling->color = RED;
                child = parent;
                parent = child->parent;
            } else {
                if (!sibling->left || sibling->left->color == BLACK) {
                    sibling->right->color = BLACK;
                    sibling->color = RED;
                    RRRotationRBT(root, sibling);
                    sibling = parent->left;
                }
                sibling->color = parent->color;
                parent->color = BLACK;
                sibling->left->color = BLACK;
                LLRotationRBT(root, parent);
                child = *root;
                break;
            }
        }
    }
    // 若child为红色,将其变为黑色即可满足性质
    if (child) {
        child->color = BLACK;
    }
}
void projectRBT(Tnode *root) {
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
        printf("请输入你的选择:\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("请输入添加的数据:\n");
                scanf("%d", &data);
                insertRBT(&root, data);
                break;
            case 2:
                printf("请输入删除的数据:\n");
                scanf("%d", &delData);
                delRBT(&root, delData);
                break;
            case 3:
                printf("前序遍历:");
                preOrderRBT(root);
                printf("\n");
                break;
            case 4:
                printf("中序遍历:");
                inOrderRBT(root);
                printf("\n");
                break;
            case 5:
                printf("后序遍历:");
                postOrderRBT(root);
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
