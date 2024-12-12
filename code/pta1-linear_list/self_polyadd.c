#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100000

typedef struct Poly{
    int XS;
    int ZS;
}Poly;

void read_poly(Poly* stack, int* stack_num){
    int n;
    scanf("%d",&n);
    *stack_num = n-1; //记得减一
    for (int i=0;i<n;i++){
        scanf("%d %d",&stack[i].XS,&stack[i].ZS);
    }
}

void print_poly(Poly* stack, int stack_num){
    if (stack_num == 0){ //等于独立输出
        printf("0 0");
    }
    for (int i=0;i<stack_num;i++){
        printf("%d %d",stack[i].XS, stack[i].ZS);
        if (i != stack_num-1){ //记得减一
            printf(" ");
        }
    }
}

void add_poly(Poly* stack_1,int stack_1_num,Poly* stack_2,int stack_2_num,Poly* stack_add,int *stack_add_num){
    int i=0, j=0, k=0; //下标当成指针用，不要搞混指针
    while(i <= stack_1_num && j<= stack_2_num){
        if (stack_1[i].ZS < stack_2[j].ZS){ //谁大用谁赋值
            stack_add[k++] = stack_2[j++];
        }
        else if(stack_1[i].ZS > stack_2[j].ZS){
            stack_add[k++] = stack_1[i++];
        }
        else{
            int sum = stack_1[i].XS + stack_2[j].XS;
            if (sum != 0){ //等于0记得跳过加到add栈里
                stack_add[k].XS = sum;
                stack_add[k].ZS = stack_1[i].ZS;
                k++;
            }
            i++;
            j++;
        }
    }
    while(i <= stack_1_num){ //用while不用if
        stack_add[k++] = stack_1[i++];
    }
    while(j <= stack_2_num){ //用while不用if
        stack_add[k++] = stack_2[j++];
    }
    *stack_add_num = k;
}

int main(){
    Poly stack_1[MAXSIZE] = {0}; //记得初始化
    Poly stack_2[MAXSIZE] = {0};
    Poly stack_add[MAXSIZE] = {0};
    int stack_1_num=0, stack_2_num = 0, stack_add_num = 0;

    read_poly(stack_1,&stack_1_num);
    read_poly(stack_2,&stack_2_num);

    add_poly(stack_1, stack_1_num, stack_2, stack_2_num, stack_add, &stack_add_num);

    print_poly(stack_add, stack_add_num);
}