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
    // ��ȡ����ڵ�ĸ��ڵ�
    while (current) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    // ����
    temp->parent = parent;
    if (parent) {
        if (data < parent->data) {
            parent->left = temp;
        } else {
            parent->right = temp;
        }
    } else {
        // ��parentΪ�գ������ڵ�Ϊ���ڵ�
        *root = temp;
    }
    // ��������
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
    // ��parentΪ��,��nodeΪ���ڵ�
    // ��parentΪ��ɫ,����Ҫ����
    while ((parent = (*node)->parent) && parent->color == RED) {
        grandparent = parent->parent;
        // ���Ҿ������
        // ��parentΪgrandparent����ڵ�
        if (parent == grandparent->left) {
            Tnode *uncle = grandparent->right;
            // ��uncleΪ��ɫ
            if (uncle && uncle->color == RED) {
                uncle->color = BLACK;
                parent->color = BLACK;
                grandparent->color = RED;
                // ͨ����������node,ͨ��node��ȡparent��grandparent�����ϻ���
                *node = grandparent;
                continue;
            }
            // ��uncleΪ��ɫ(����uncleΪ�յ����)
            // ����ڵ�Ϊparent���ҽڵ�(��ʱ���ΪLR)
            if (parent->right == *node) {
                RRRotationRBT(root, parent);
                // ��תʱ����ı�parent��node,ֻ��ı�λ�ã���ת��parentΪnode����ڵ�
                // ����parent��node
                Tnode *temp = parent;
                parent = *node;
                *node = temp;
            }
            parent->color = BLACK;
            grandparent->color = RED;
            LLRotationRBT(root, grandparent);
        } else {
            // ��parentΪgrandparent���ҽڵ�
            Tnode *uncle = grandparent->left;
            // ��uncleΪ��ɫ
            if (uncle && uncle->color == RED) {
                uncle->color = BLACK;
                parent->color = BLACK;
                grandparent->color = RED;
                *node = grandparent;
                continue;
            }
            // ��uncleΪ��ɫ
            // �����parent����ڵ�(��ʱ���ΪRL)
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
    printf("����������:(��-1��������)\n");
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
    // ��ȡɾ���ڵ�
    while (delNode->data != data) {
        if (data < delNode->data) {
            if (delNode->left) {
                delNode = delNode->left;
            } // �˴����data�Ƿ����������
        } else if (data > delNode->data) {
            if (delNode->right) {
                delNode = delNode->right;
            } // �˴����data�Ƿ����������
        }
    }
    // ɾ��
    if (!delNode->left && !delNode->right) { // ��delNode�����ҽڵ㶼Ϊ��
        parent = delNode->parent;
        if (delNode == *root) {
            *root = NULL;
        } else if (parent->left == delNode) { // ��delNodeΪparent����ڵ�
            parent->left = NULL;
        } else if (parent->right == delNode) { // ��delNodeΪparent���ҽڵ�
            parent->right = NULL;
        }
    } else if (!delNode->left && delNode->right) { // ��delNode����ڵ�Ϊ��,�ҽڵ㲻Ϊ��
        child = delNode->right;
        parent = delNode->parent;
        if (delNode == *root) {
            *root = child;
            child->parent = NULL;
        }
        else if (parent->left == delNode) { // ��delNodeΪparent����ڵ�
            parent->left = child;
            child->parent = parent;
        } else if (parent->right == delNode) { // ��delNodeΪparent���ҽڵ�
            parent->right = child;
            child->parent = parent;
        }
    } else if (delNode->left && !delNode->right) { // ��delNode����ڵ㲻Ϊ��,�ҽڵ�Ϊ��
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
    } else { // ��delNode�����ҽڵ㶼��Ϊ��
        // ��ȡ�����̽ڵ�
        Tnode *successor = delNode->right;
        while (successor->left) {
            successor = successor->left;
        }
        // ��successor(�����̽ڵ�)���滻
        // ��delNode->parent��Ϊ�գ���delNode���Ǹ��ڵ�
        if (delNode->parent) {
            // ��delNode��parent���ӵ�successor
            if (delNode->parent->left == delNode) {
                delNode->parent->left = successor;
            } else {
                delNode->parent->right = successor;
            }
        } else { // ��delNodeΪ���ڵ�
            *root = successor;
        }

        // ��successor��parent��child�Ĵ���
        // ���¶�child�Ĵ����Ϊ�������:
        // ��delNodeΪsuccessor���ҽڵ�ʱ,����Ҫ����child,ֻ�轫delNode�滻Ϊsuccessor
        // ��delNode��Ϊsuccessor���ҽڵ�ʱ,��Ҫ����child,��child��successor��parent����

        // successorһ��û����ڵ�
        child = successor->right;
        parent = successor->parent;
        int color = successor->color;
        // ��successorΪdelNode���ҽڵ�
        if (parent == delNode) {
            parent = successor;
        } else { // ��successor��ΪdelNode���ҽڵ�
            if (child) {
                child->parent = parent;
            }
            parent->left = child;
            // ��delNode�ҽڵ�Ĵ���
            successor->right = delNode->right;
            delNode->right->parent = successor;
        }
        // �滻delNode��successor
        successor->parent = delNode->parent;
        successor->left = delNode->left;
        delNode->left->parent = successor;
        successor->color = delNode->color;
        // ��������
        // ��delNodeΪ��ɫ,����Ҫ����
        if (color == BLACK) {
            // child���¾���������,��child��ʼ����
            updateDRBT(root, child, parent);
        }
        return;
    }
    // ��������
    // ��delNodeΪ��ɫ,����Ҫ����
    if (delNode->color == BLACK) {
        // child���¾���������,��child��ʼ����
        updateDRBT(root, child, parent);
    }
}
// childΪ�������ĵ�
void updateDRBT(Tnode **root, Tnode *child, Tnode *parent) {
    Tnode *sibling;
    // ��childΪ��ɫ��սڵ�
    // �����������Ҫ����:
    // 1.siblingΪ��ɫ,���ҽڵ�Ϊ��ɫ
    // ת��Ϊ���2
    // 2.siblingΪ��ɫ,���ҽڵ�Ϊ��
    // ��sibling��Ϊ��ɫ,֮�����ϻ���,ֱ������ѭ��
    // 3.siblingΪ��ɫ,��ڵ�Ϊ��ɫ
    // ת��Ϊ���4
    // 4.siblingΪ��ɫ,�ҽڵ�Ϊ��ɫ
    // 5.siblingΪ��ɫ,���ҽڵ�Ϊ��ɫ
    // sibling����ɫ��Ϊparent����ɫ,parent���,sibling�ҽڵ���,��parent����,child��Ϊroot

    // ��childΪ���ڵ�,��Ϊchild���¾���������,���Բ���Ҫ����
    while ((!child || child->color == BLACK) && child != *root) {
        // ���Ҿ������
        if (parent->left == child) {
            sibling = parent->right;
            // ���1ת��Ϊ���2
            if (sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                RRRotationRBT(root, parent);
                sibling = parent->right;
            }
            // �������2
            if ((!sibling->left || sibling->left->color == BLACK) &&
                (!sibling->right || sibling->right->color == BLACK)) {
                sibling->color = RED;
                // ���ϻ���
                child = parent;
                parent = child->parent;
            } else { // �������3,4,5
                // �����3ת��Ϊ���4
                if (!sibling->right || sibling->right->color == BLACK) {
                    sibling->left->color = BLACK;
                    sibling->color = RED;
                    LLRotationRBT(root, sibling);
                    sibling = parent->right;
                }
                // �������4,5
                // ��������ͬ,����״̬��ͬ,����������
                sibling->color = parent->color;
                parent->color = BLACK;
                sibling->right->color = BLACK;
                RRRotationRBT(root, parent);
                child = *root;
                break;
            }
        } else { // �������,ͬ��
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
    // ��childΪ��ɫ,�����Ϊ��ɫ������������
    if (child) {
        child->color = BLACK;
    }
}
void projectRBT(Tnode *root) {
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
        printf("���������ѡ��:\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("��������ӵ�����:\n");
                scanf("%d", &data);
                insertRBT(&root, data);
                break;
            case 2:
                printf("������ɾ��������:\n");
                scanf("%d", &delData);
                delRBT(&root, delData);
                break;
            case 3:
                printf("ǰ�����:");
                preOrderRBT(root);
                printf("\n");
                break;
            case 4:
                printf("�������:");
                inOrderRBT(root);
                printf("\n");
                break;
            case 5:
                printf("�������:");
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
