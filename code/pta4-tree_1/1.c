#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义节点结构
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

// 创建新节点
Node* newNode(int item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// 插入节点到二叉搜索树
Node* insert(Node* node, int key) {
    if (node == NULL) {
        return newNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

// 查找并输出给定层的节点
void printGivenLevel(Node* root, int level, int currentLevel) {
    if (root == NULL) {
        return;
    }
    if (currentLevel == level) {
        printf("%d,", root->key);
    } else {
        printGivenLevel(root->left, level, currentLevel + 1);
        printGivenLevel(root->right, level, currentLevel + 1);
    }
}

// 计算二叉树的最大深度
int maxDepth(Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}

int main() {
    int n;
    char sequence[100];
    int level;

    // 输入部分
    scanf("%d", &n);
    getchar(); // 读取换行符
    fgets(sequence, sizeof(sequence), stdin);
    scanf("%d", &level);

    // 处理输入的整数序列
    int keys[20];
    int keyCount = 0;
    char* token = strtok(sequence, ",");
    while (token != NULL) {
        keys[keyCount++] = atoi(token);
        token = strtok(NULL, ",");
    }

    // 构建二叉搜索树
    Node* root = NULL;
    for (int i = 0; i < keyCount; i++) {
        root = insert(root, keys[i]);
    }

    // 输出特定层的节点
    if (level > maxDepth(root)) {
        printf("-1\n");
    } else {
        printGivenLevel(root, level, 1);
        printf("\n");
    }

    return 0;
}
