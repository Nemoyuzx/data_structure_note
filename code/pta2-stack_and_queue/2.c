#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50  // 定义表达式的最大长度

char stack[MAX_LENGTH];  // 定义栈用于存储括号字符
int top = -1;  // 初始化栈顶指针为-1，表示栈为空

// 将字符压入栈
void push(char ch) {
    stack[++top] = ch;
}

// 从栈中弹出字符
void pop() {
    if (top >= 0) {
        top--;
    }
}

// 查看栈顶的字符
char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';  // 如果栈为空，返回空字符
}

int main() {
    char expression[MAX_LENGTH];  // 存储输入的表达式
    fgets(expression, MAX_LENGTH, stdin);  // 从标准输入读取表达式
    int length = strlen(expression);  // 计算表达式的长度

    // 重置栈
    top = -1;
    int unbalanced[3] = {0, 0, 0};  // 用于标记未匹配的括号类型，0表示匹配，1表示不匹配

    // 遍历表达式中的每个字符
    for (int i = 0; i < length; i++) {
        char ch = expression[i];
        switch (ch) {
            case '(':
            case '[':
            case '{':
                push(ch);  // 如果是左括号，将其压入栈
                break;
            case ')':
                if (peek() == '(') {
                    pop();  // 如果是右括号且栈顶是匹配的左括号，则弹出栈顶
                } else {
                    unbalanced[0] = 1;  // 否则标记圆括号不匹配
                }
                break;
            case ']':
                if (peek() == '[') {
                    pop();  // 如果是右括号且栈顶是匹配的左括号，则弹出栈顶
                } else {
                    unbalanced[1] = 1;  // 否则标记方括号不匹配
                }
                break;
            case '}':
                if (peek() == '{') {
                    pop();  // 如果是右括号且栈顶是匹配的左括号，则弹出栈顶
                } else {
                    unbalanced[2] = 1;  // 否则标记大括号不匹配
                }
                break;
        }
    }

    // 检查栈中是否还有未匹配的左括号
    while (top >= 0) {
        char unmatched = peek();
        if (unmatched == '(') {
            unbalanced[0] = 1;  // 如果栈顶是圆括号，标记其为不匹配
        } else if (unmatched == '[') {
            unbalanced[1] = 1;  // 如果栈顶是方括号，标记其为不匹配
        } else if (unmatched == '{') {
            unbalanced[2] = 1;  // 如果栈顶是大括号，标记其为不匹配
        }
        pop();  // 弹出栈顶
    }

    // 输出不匹配的括号类型，后面加逗号
    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (unbalanced[i]) {
            printf("%d,", i + 1);  // 输出不匹配的括号类型编号（1：圆括号，2：方括号，3：大括号）
            count++;
        }
    }
    if (count == 0) {
        printf("0");  // 如果没有不匹配的括号，输出0
    }
    printf("\n");

    return 0;
}