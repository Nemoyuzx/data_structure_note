#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;

Node *create(int n){
    Node *head_node = (Node*)malloc(sizeof(Node));
    head_node->data = 1;
    head_node->next = NULL;
    Node* prev = head_node;
    
    for (int i=2;i<=n;i++){
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node->data = i;
        prev->next = new_node;
        new_node->next = NULL;
        prev = new_node;
    }
    prev->next = head_node;
    return head_node;
}

void play(int n,int m){
    Node* head = create(n);
    Node* current = head;
    Node* previous = NULL;

    int count = 0;
    while(count<n){
        for (int i=0;i<m;i++){
            previous = current;
            current = current->next;
        }

        printf("%d",current->data);
        if(count < n-1){
            printf(",");
        }

        previous->next = current->next;
        free(current);
        current = previous->next;
        count++;
    }
    printf("\n");
}

int main(){
    int n,m;
    scanf("%d,%d",&n,&m);
    play(n,m);
}
