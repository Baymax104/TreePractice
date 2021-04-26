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
    *node = temp;// �ı���ڵ�
}
void singleRightRotationAVL(Tnode **node) {
    Tnode *temp = (*node)->right;
    (*node)->right = temp->left;
    temp->left = *node;
    (*node)->height = MAX(getHeightAVL((*node)->left),
                          getHeightAVL((*node)->right)) + 1;
    temp->height = MAX(getHeightAVL((*node)->right),
                       (*node)->height) + 1;
    *node = temp;// �ı���ڵ�
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
                // ���������������������(LL),����
                singleLeftRotationAVL(node);
            } else {
                // ���������������������(LR)
                doubleLeftRotationAVL(node);
            }
        }
    } else {
        insertAVL(&(*node)->right, data);
        if (2 == getHeightAVL((*node)->right) - getHeightAVL((*node)->left)) {
            if (data > (*node)->right->data) {
                // ���������������������(RR),����
                singleRightRotationAVL(node);
            } else {
                // ���������������������(RL)
                doubleRightRotationAVL(node);
            }
        }
    }
    (*node)->height = MAX(getHeightAVL((*node)->right),
                          getHeightAVL((*node)->left)) + 1;
}
void createTreeAVL(Tnode **node) {
    int data;
    printf("����������:(��-1��������)\n");
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
            // �����֧�ڵ�
            Tnode *temp = (*node)->right;
            while (temp->left) {
                temp = temp->left;
            }
            (*node)->data = temp->data;
            delNodeAVL(&(*node)->right, temp->data);// ɾ����������С�ڵ�
            // ɾ���ýڵ��ض��������߶� > �������߶�
            // ��ɾ�����������߶� > �������߶ȣ�����ɾ��ǰ�Ͳ�ƽ��
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
                Tnode **temp = node;// ��Ҫ�޸�*node��ֵ������ֱ���޸ģ�ʹ��**temp�����޸�
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
        printf("1)��ӽڵ�\n");
        printf("2)ɾ���ڵ�\n");
        printf("3)ǰ�����\n");
        printf("4)�������\n");
        printf("5)�������\n");
        printf("6)�˳�\n");
        printf("���������ѡ��:\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("������Ҫ���������:\n");
                scanf("%d", &insertData);
                insertAVL(&node, insertData);
                break;
            case 2:
                printf("������Ҫɾ��������:\n");
                scanf("%d", &delData);
                delNodeAVL(&node, delData);
                break;
            case 3:
                printf("ǰ�����:");
                preOrderAVL(node);
                printf("\n");
                break;
            case 4:
                printf("�������:");
                inOrderAVL(node);
                printf("\n");
                break;
            case 5:
                printf("�������:");
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
