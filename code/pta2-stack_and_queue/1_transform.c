#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXSIZE 100

// 定义一个用于字符的栈结构（用于存储操作符和括号）
typedef struct Stack {
    char items[MAXSIZE];
    int top;
} Stack;

// 定义一个用于双精度值的栈结构（用于计算后缀表达式）
typedef struct StackDouble {
    double items[MAXSIZE];
    int top;
} StackDouble;

// 初始化字符栈
void initStack(Stack* s) {
    s->top = -1;
}

// 检查字符栈是否为空
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 将一个字符压入栈中
void push(Stack* s, char value) {
    s->items[++(s->top)] = value;
}

// 从栈中弹出一个字符
char pop(Stack* s) {
    if (isEmpty(s)) return -1; // 如果栈为空，返回 -1
    return s->items[(s->top)--];
}

// 查看栈顶的字符但不移除它
char peek(Stack* s) {
    return s->items[s->top];
}

// 初始化用于双精度值的栈
void initStackDouble(StackDouble* s) {
    s->top = -1;
}

// 将一个双精度值压入栈中
void pushDouble(StackDouble* s, double value) {
    s->items[++(s->top)] = value;
}

// 从栈中弹出一个双精度值
double popDouble(StackDouble* s) {
    return s->items[(s->top)--];
}

// 确定操作符的优先级
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1; // 加法和减法的优先级较低
        case '*':
        case '/': return 2; // 乘法和除法的优先级较高
        default: return 0;
    }
}

// 检查字符是否是操作符
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// 检查字符是否是左括号
int isLeftBracket(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

// 检查字符是否是右括号
int isRightBracket(char ch) {
    return ch == ')' || ch == '}' || ch == ']';
}

// 判断左右括号是否匹配
int isMatchingBracket(char left, char right) {
    return (left == '(' && right == ')') || (left == '{' && right == '}') || (left == '[' && right == ']');
}

// 将中缀表达式转换为后缀表达式
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if (isdigit(ch)) {
            // 如果字符是数字，将其添加到后缀表达式中
            postfix[j++] = ch;
            postfix[j++] = ' '; // 在数字后添加空格用于分隔
        } else if (isLeftBracket(ch)) {
            // 如果字符是左括号，将其压入栈中
            push(&s, ch);
        } else if (isRightBracket(ch)) {
            // 如果字符是右括号，从栈中弹出直到遇到匹配的左括号
            while (!isEmpty(&s) && !isMatchingBracket(peek(&s), ch)) {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            pop(&s); // 将匹配的左括号从栈中移除
        } else if (isOperator(ch)) {
            // 如果字符是操作符
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                // 弹出栈中优先级大于或等于当前操作符的所有操作符，并将其添加到后缀表达式中
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            // 将当前操作符压入栈中
            push(&s, ch);
        }
    }
    // 弹出栈中所有剩余的操作符
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';
    }
    postfix[j] = '\0'; // 在后缀表达式末尾添加空字符
}

// 计算后缀表达式的值
double evaluatePostfix(char* postfix) {
    StackDouble s;
    initStackDouble(&s);
    int i = 0;
    char ch;
    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            // 如果字符是数字，将其值压入栈中
            pushDouble(&s, ch - '0');
        } else if (isOperator(ch)) {
            // 如果字符是操作符，弹出两个值并应用操作符
            double b = popDouble(&s);
            double a = popDouble(&s);
            switch (ch) {
                case '+': pushDouble(&s, a + b); break; // 执行加法操作
                case '-': pushDouble(&s, a - b); break; // 执行减法操作
                case '*': pushDouble(&s, a * b); break; // 执行乘法操作
                case '/': pushDouble(&s, a / b); break; // 执行除法操作
            }
        }
    }
    // 最终结果是栈中最后一个剩余的值
    return popDouble(&s);
}

int main() {
    char infix[MAXSIZE];
    char postfix[MAXSIZE];
    // 从用户输入读取中缀表达式
    fgets(infix, MAXSIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // 去除输入中的换行符
    
    // 将中缀表达式转换为后缀表达式
    infixToPostfix(infix, postfix);
    // 计算后缀表达式的值
    double result = evaluatePostfix(postfix);
    // 打印计算结果（保留两位小数）
    printf("%.2f\n", result);
    // 打印后缀表达式
    printf("%s\n", postfix);
    
    return 0;
}