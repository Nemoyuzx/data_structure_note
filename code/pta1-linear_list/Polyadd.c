#include <stdio.h>  // 引入标准输入输出库
#include <stdlib.h> // 引入标准库函数

#define STACK_SIZE 50  // 定义栈的最大大小为50

typedef struct{
    int coefficient;  // 系数
    int index;        // 指数
}Term;                // 用于存储多项式项的结构体

// 读取多项式的函数
void readPoly(Term Stack[],int *term_num){
    int n;
    scanf("%d",&n);  // 读取多项式的项数
    *term_num = n-1;  // 存储多项式的项数（索引从0开始，因此实际为n-1）
    for (int i=0;i<n;i++){
        scanf("%d %d",&Stack[i].coefficient,&Stack[i].index);  // 依次读取每项的系数和指数
    }
}

// 输出多项式的函数
void outputPoly(Term Stack[],int term_num){
    if (term_num == 0){
        printf("0 0");  // 如果多项式只有一项且系数为0，输出"0 0"
        return;
    }
    for(int i = 0;i<term_num;i++){
        printf("%d %d",Stack[i].coefficient,Stack[i].index);  // 输出每一项的系数和指数
        if (i != term_num-1){
            printf(" ");  // 如果不是最后一项，则在输出后添加空格
        }
    }
}

// 合并两个多项式的函数
void combinePoly(Term Stack_fir[], int term_fir_num, Term Stack_sec[], int term_sec_num, Term Stack_add[], int *term_add_num) {
    int i = 0, j = 0, k = 0;  // 初始化三个指针，分别指向两个输入多项式和合并后的多项式
    while (i <= term_fir_num && j <= term_sec_num) {
        if (Stack_fir[i].index > Stack_sec[j].index) {  // 如果第一个多项式当前项的指数大于第二个多项式当前项的指数
            Stack_add[k++] = Stack_fir[i++];  // 将第一个多项式的当前项添加到结果中，移动指针
        } else if (Stack_fir[i].index < Stack_sec[j].index) {  // 如果第二个多项式当前项的指数大于第一个多项式当前项的指数
            Stack_add[k++] = Stack_sec[j++];  // 将第二个多项式的当前项添加到结果中，移动指针
        } else {  // 如果两个多项式当前项的指数相等
            int sum = Stack_fir[i].coefficient + Stack_sec[j].coefficient;  // 计算两个项的系数和
            if (sum != 0) {  // 如果系数和不为0，则添加到结果中
                Stack_add[k].coefficient = sum;
                Stack_add[k].index = Stack_fir[i].index;
                k++;
            }
            i++;  // 移动两个输入多项式的指针
            j++;
        }
    }
    while (i <= term_fir_num) {  // 如果第一个多项式还有剩余项
        Stack_add[k++] = Stack_fir[i++];  // 将剩余项添加到结果中
    }
    while (j <= term_sec_num) {  // 如果第二个多项式还有剩余项
        Stack_add[k++] = Stack_sec[j++];  // 将剩余项添加到结果中
    }
    *term_add_num = k;  // 更新合并后多项式的项数
}

int main(){
    Term Stack_1[STACK_SIZE] = {0};  // 定义第一个多项式的数组，并初始化为0
    int Stack_1_num = 0;  // 定义第一个多项式的项数
    Term Stack_2[STACK_SIZE] = {0};  // 定义第二个多项式的数组，并初始化为0
    int Stack_2_num = 0;  // 定义第二个多项式的项数

    Term Stack_add[STACK_SIZE] = {0};  // 定义存储合并后多项式的数组，并初始化为0
    int Stack_add_num = 0;  // 定义合并后多项式的项数

    readPoly(Stack_1,&Stack_1_num);  // 读取第一个多项式
    readPoly(Stack_2,&Stack_2_num);  // 读取第二个多项式

    combinePoly(Stack_1,Stack_1_num,Stack_2,Stack_2_num,Stack_add,&Stack_add_num);  // 合并两个多项式

    outputPoly(Stack_add,Stack_add_num);  // 输出合并后的多项式
}

/*
总结：
1. 这段代码的作用是读取两个多项式，然后将它们合并，最后输出合并后的结果。
2. 使用了结构体Term来存储多项式的系数和指数，并使用数组来表示多项式。
3. readPoly函数用于从输入中读取多项式，outputPoly函数用于输出多项式，combinePoly函数用于合并两个多项式。
4. 主函数通过调用这些函数实现了多项式的读取、合并和输出的完整流程。
*/