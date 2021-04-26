/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/9 13:45
*@Version
*/

#include "HuffmanTree.h"
/*int main () {
    printf("请输入权值个数:\n");
    scanf("%d", &numberOfWeight);
    initHeapHT();
    initTreeHT();
    enterWeightHT();
    createTreeHT();
    printf("哈夫曼树:\n");
    listTreeHT();
    printf("哈夫曼编码:\n");
    listCodeHT();
    return 0;
}*/
void enterWeightHT() {
    int data;
    printf("请输入权值:(按-1结束输入)\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) break;
        pushHT(data);
    }
}
void initTreeHT() {
    // 最小堆有n个元素,则树中有2n-1个节点
    tree = (Node*)malloc(sizeof(Node) * 2 * numberOfWeight);
    for (int i = 0; i < 2 * numberOfWeight; i++) {
        tree[i].weight = 0;
        tree[i].parent = -1;
        tree[i].left = -1;
        tree[i].right = -1;
    }
}
void initHeapHT() {
    heap = (Heap*)malloc(sizeof(Heap));
    heap->data = (int*)malloc(sizeof(int) * numberOfWeight);
    heap->size = -1;
}
void swapHT(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void pushHT(int data) {
    heap->size++;
    heap->data[heap->size] = data;
    shiftUpHT();
}
int popHT() {
    int popData = heap->data[0];
    heap->data[0] = heap->data[heap->size];
    heap->size--;
    shiftDownHT();
    return popData;
}
void shiftUpHT() {
    int data = heap->data[heap->size];
    for (int i = heap->size; heap->data[(i - 1) / 2] > data && i != 0; i = (i - 1) / 2) {
        swapHT(&heap->data[i], &heap->data[(i - 1) / 2]);
    }
}
void shiftDownHT() {
    int parent = 0;
    int child = parent * 2 + 1;
    while (child <= heap->size) {
        if (child + 1 <= heap->size && heap->data[child] > heap->data[child + 1]) {
            child = child + 1;
        }
        if (heap->data[parent] > heap->data[child]) {
            swapHT(&heap->data[parent], &heap->data[child]);
        } else {
            break;
        }
        parent = child;
        child = parent * 2 + 1;
    }
}
void findIndexHT(int min1Value, int min2Value, int *min1, int *min2, int current) {
    int temp1 = *min1, temp2 = *min2;
    for (int i = numberOfWeight; i < 2 * numberOfWeight - 1; i++) {
        if (tree[i].weight == min1Value) {
            *min1 = i;
        }
        if (tree[i].weight == min2Value) {
            *min2 = i;
        }
    }
    if (temp1 == *min1) {
        *min1 = current;
    }
    if (temp2 == *min2) {
        *min2 = current;
    }
    if (*min1 < numberOfWeight) {
        *min1 = current;
    }
    if (*min2 < numberOfWeight) {
        *min2 = current;
        if (*min2 == *min1) {
            (*min2)++;
        }
    }
}
void createTreeHT() {
    int left;
    int right;
    int leftIndex = 0;
    int rightIndex = 1;
    int current = 0;
    int j = numberOfWeight;

    while (heap->size != -1) {
        left = popHT();
        right = popHT();
        tree[j].weight = left + right;

        // 查找left,right索引
        findIndexHT(left, right, &leftIndex, &rightIndex, current);
        tree[leftIndex].weight = left;
        tree[rightIndex].weight = right;

        // 将current设为SIZE之前第一个权值不是0的位置
        for (int i = 0; i < numberOfWeight; i++) {
            if (tree[i].weight == 0) {
                current = i;
                break;
            }
        }

        // 父节点和子节点连接
        tree[leftIndex].parent = j;
        tree[rightIndex].parent = j;
        tree[j].left = leftIndex;
        tree[j].right = rightIndex;
        j++;

        pushHT(left + right);
    }

}
void encodeHT(char *code, int weight) {
    int parent = 0;
    int child;
    int i;
    int codeIndex = 0;
    for (i = 0; i < numberOfWeight; i++) {
        if (tree[i].weight == weight) {
            break;
        }
    }
    child = i;
    while (parent != 2 * numberOfWeight - 2) {
        parent = tree[child].parent;
        if (tree[parent].left == child) {
            code[codeIndex] = '0';
            codeIndex++;
        } else {
            code[codeIndex] = '1';
            codeIndex++;
        }
        child = parent;
    }
}
void listTreeHT() {
    for (int i = 0; i < 2 * numberOfWeight - 1; i++) {
        printf("%d %d %d %d\n", tree[i].weight, tree[i].parent, tree[i].left, tree[i].right);
    }
}
void listCodeHT() {
    char *code;
    code = (char *) malloc(sizeof(char) * numberOfWeight);
    memset(code, '\0', sizeof(char) * numberOfWeight);
    for (int i = 0; i < numberOfWeight; i++) {
        encodeHT(code, tree[i].weight);
        printf("%d : %s\n", tree[i].weight, code);
        memset(code, '\0', sizeof(char) * numberOfWeight);
    }
}
