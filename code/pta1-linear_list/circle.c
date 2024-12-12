#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_circle(int n) {
    Node* head = malloc(sizeof(Node));
    head->data = 1;
    Node* prev = head;

    for (int i = 2; i <= n; i++) {
        Node* new_node = malloc(sizeof(Node));
        new_node->data = i;
        prev->next = new_node;
        prev = new_node;
    }
    prev->next = head; // 形成循环
    return head;
}

void josephus_game(int n, int m) {
    Node* head = create_circle(n);
    Node* current = head;
    Node* prev = NULL;

    int count = 0;
    while (count < n) {
        // 找到要删除的节点
        for (int i = 1; i <= m; i++) {
            prev = current;
            current = current->next;
        }

        printf("%d", current->data); // 输出被删除的人的编号
        if (count < n - 1) {
            printf(","); // 不是最后一个，输出逗号
        }

        // 删除节点
        prev->next = current->next; // 更新指针，跳过要删除的节点
        free(current); // 释放内存

        current = prev->next; // 移动到下一个节点
        count++;
    }
    printf("\n");
}

int main() {
    int n, m;
    //printf("请输入 N 和 M (例如：5,1): ");
    scanf("%d,%d", &n, &m);
    
    if (n <= 0 || m <= 0 || m > n) {
        printf("输入的 N 和 M 不合法！\n");
        return 1;
    }

    josephus_game(n, m);
    return 0;
}
