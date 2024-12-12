#include <stdio.h>
#include <string.h>//记得库

#define MAX 50

char cha[MAX];
int top = -1;

//压、弹、找
void push(char ch){
    cha[++top] = ch;
}

char pop(){
    if (top >= 0) return top--;
}

char peek(){
    if (top!=-1) return cha[top];
    else return '\0';
}

int main(){

    int unbalanced[3] = {0,0,0};

    char input[MAX];
    fgets(input,MAX,stdin);//记得fgets
    int length = strlen(input);

    top = -1;//记得重置栈

    for (int i=0;i<length;i++){//for循环逐个遍历字符
        char ch = input[i];
        switch (ch){
            case '(':
            case '[':
            case '{':
                push(ch);
                break;//记得break
            case ')'://查找有就pop，无就该标记
                if (peek()=='('){
                    pop();
                }
                else{
                    unbalanced[0] = 1;
                }
                break;//记得break
            case ']':
                if (peek()=='['){
                    pop();
                }
                else{
                    unbalanced[1] = 1;
                }
                break;//记得break
            case '}':
                if (peek()=='{'){
                    pop();
                }
                else{
                    unbalanced[2] = 1;
                }
                break;//记得break
        }
    }
    while (top >= 0){//记得检查栈中剩余
        char ch = peek();
        if (ch == '('){
            unbalanced[0] = 1;
        }
        else if (ch == '['){
            unbalanced[1] = 1;
        }
        else if (ch == '{'){
            unbalanced[2] = 1;
        }
        pop();
    }

    int count = 1;//记得用flag标记法
    for (int i=0;i<=2;i++){
        if (unbalanced[i]){
            printf("%d,",i+1);
            count = 0;
        }
    }
    if (count){
        printf("0");
    }
    printf("\n");//记得加换行

}