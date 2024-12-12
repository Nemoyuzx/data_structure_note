#include <stdio.h>
#include <stdlib.h>

// 定义双向链表节点结构
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// 插入节点到双向链表末尾
void insert_end(struct Node** head, struct Node** tail, int data) {
    // 创建新节点
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = *tail;

    // 如果链表为空，头和尾都指向新节点
    if (*tail == NULL) {
        *head = new_node;
    } else {
        (*tail)->next = new_node;  // 将新节点连接到尾部
    }
    *tail = new_node;  // 更新尾节点
}

// 判断双向链表是否为中心对称
int is_central_list(struct Node* head, struct Node* tail) {
    // 前后同时遍历链表，比较每个对应的节点
    while (head != tail && head->prev != tail) {
        if (head->data != tail->data) {
            return 0;  // 如果数据不相等，返回 0
        }
        head = head->next;  // 前指针向前
        tail = tail->prev;  // 后指针向后
    }
    return 1;  // 如果对称，返回 1
}

int main() {
    struct Node* head = NULL;  // 链表头指针
    struct Node* tail = NULL;  // 链表尾指针

    int num = 0;               // 当前累积的数字
    char ch;

    // 逐字符读取输入直到换行符
    while ((ch = getchar()) != '\n') {
        if (ch == ',') {
            // 遇到逗号时，表示一个数字结束，将其插入链表
            insert_end(&head, &tail, num);
            num = 0;  // 重置当前累积的数字
        } else if (ch >= '0' && ch <= '9') {
            // 如果是数字字符，将其添加到当前数字
            num = num * 10 + (ch - '0');
        }
    }

    // 检查双向链表是否是中心对称的
    if (is_central_list(head, tail)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // 释放链表内存
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
