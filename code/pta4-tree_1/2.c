#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义二叉树节点结构
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// 创建一个新节点
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入一个节点到二叉搜索树
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

// 前序遍历二叉树
void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d", root->key);
    if (root->left != NULL) {
        printf(",");
        preorderTraversal(root->left);
    }
    if (root->right != NULL) {
        printf(",");
        preorderTraversal(root->right);
    }
}

// 释放二叉树内存
void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 主函数
int main() {
    char input[1000];
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return EXIT_FAILURE;
    }

    // 去掉换行符
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    Node* root = NULL;
    int key;
    char* token = strtok(input, ",");

    // 根据输入创建二叉搜索树
    while (token != NULL) {
        if (sscanf(token, "%d", &key) != 1) {
            fprintf(stderr, "Invalid input\n");
            return EXIT_FAILURE;
        }
        root = insert(root, key);
        token = strtok(NULL, ",");
    }

    // 前序遍历并输出
    preorderTraversal(root);
    printf(",\n");

    // 释放内存
    freeTree(root);

    return 0;
}
