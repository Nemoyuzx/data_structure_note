#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE 256

typedef struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

Node* createNode(char character, int frequency) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

Node* priorityQueue[MAX_NODE];
int size = 0;

void enqueue(Node* node) {
    int i = size++;
    while (i > 0 && priorityQueue[(i - 1) / 2]->frequency > node->frequency) {
        priorityQueue[i] = priorityQueue[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    priorityQueue[i] = node;
}

Node* dequeue() {
    Node* root = priorityQueue[0];
    Node* temp = priorityQueue[--size];
    int i = 0, child;
    while ((child = i * 2 + 1) < size) {
        if (child + 1 < size && priorityQueue[child + 1]->frequency < priorityQueue[child]->frequency) {
            child++;
        }
        if (temp->frequency <= priorityQueue[child]->frequency) break;
        priorityQueue[i] = priorityQueue[child];
        i = child;
    }
    priorityQueue[i] = temp;
    return root;
}

Node* buildHuffmanTree(int freq[]) {
    for (char i = 'a'; i <= 'h'; ++i) {
        if (freq[i - 'a'] > 0) {
            enqueue(createNode(i, freq[i - 'a']));
        }
    }
    while (size > 1) {
        Node* left = dequeue();
        Node* right = dequeue();
        Node* newNode = createNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        enqueue(newNode);
    }
    return dequeue();
}

void generateCodes(Node* root, char* code, int length, char codes[256][100]) {
    if (root->left == NULL && root->right == NULL) {
        code[length] = '\0';
        strcpy(codes[(int)root->character], code);
        return;
    }
    if (root->left) {
        code[length] = '0';
        generateCodes(root->left, code, length + 1, codes);
    }
    if (root->right) {
        code[length] = '1';
        generateCodes(root->right, code, length + 1, codes);
    }
}


void decode(Node* root, const char* encodedString) {
    Node* current = root;
    while (*encodedString) {
        if (*encodedString == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->left == NULL && current->right == NULL) {
            printf("%c", current->character);
            current = root;
        }
        encodedString++;
    }
    printf("\n");
}

int main() {

    int freq[8] = {7, 19, 2, 6, 32, 3, 21, 10};
    
    Node* root = buildHuffmanTree(freq);

    char codes[256][100] = {0};
    char code[100];
    generateCodes(root, code, 0, codes);

    char encodedString[101];
    scanf("%100s", encodedString);

    decode(root, encodedString);
    
    return 0;
}
