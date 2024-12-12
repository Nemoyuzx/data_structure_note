#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleNode
{
    int data;
    struct DoubleNode* prev;
    struct DoubleNode* next;
}DNode;

void insert_DLK(DNode** head_LK, DNode** tail_LK, int data){
    DNode *node = (DNode* )malloc(sizeof(DNode));
    node->data = data;
    node->next = NULL;
    node->prev = *tail_LK;

    if (*tail_LK == NULL){ //注意
        *head_LK = node;
    }
    else{
        (*tail_LK)->next = node;
    }
    (*tail_LK) = node;
}

int is_sym(DNode* head_LK, DNode* tail_LK){
    while(head_LK != tail_LK && head_LK->prev != tail_LK){ //注意是head->prev
        if(head_LK->data != tail_LK->data){
            return 0;
        }
        head_LK = head_LK->next;
        tail_LK = tail_LK->prev;
    }
    return 1;
}

int main(){
    DNode* head_LK = NULL;
    DNode* tail_LK = NULL;

    char ch;
    int num = 0;
    while((ch = getchar()) != '\n'){ //单引号不是双引号
        if (ch == ','){ //单引号不是双引号
            insert_DLK(&head_LK, &tail_LK, num);//要改变传指针地址
            num = 0;
        }
        else if(ch >='0' && ch <= '9'){
            num = num*10+(ch-'0');
        }
    }

    if(is_sym(head_LK, tail_LK)){//不改变直接传指针指向的值
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}