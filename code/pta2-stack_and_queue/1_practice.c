#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Max_length 100

typedef struct Stack
{
    char stack[Max_length];
    int top;
}Stack;

typedef struct DoubleStack
{
    double stack[Max_length];
    int top;
}DoubleStack;

void init_Stack(Stack* s){
    s->top = -1;
}

void init_DoubleStack(DoubleStack* s){
    s->top = -1;
}

int isEmptyStack(Stack* s){
    if (s->top == -1) return 1;
    else return 0;
}

void pushStack(Stack* s,char data){
    s->stack[++(s->top)] = data;
}

char popStack(Stack* s){
    if (isEmptyStack(s)) return -1;
    return s->stack[(s->top)--];
}

char peekStack(Stack* s){
    return s->stack[(s->top)];
}

void pushDStack(DoubleStack* s,double data){
    s->stack[++(s->top)] = data;
}

double popDStack(DoubleStack* s){
    return s->stack[(s->top)--];
}

int precedence(char Operator){
    switch (Operator)
    {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    default: return 0;
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

void infix_to_fontfix(char* infix,char* postfix){
    Stack s;
    init_Stack(&s);

    int i=0,j=0;
    char ch;
    while((ch=infix[i++])!='\0'){
        if (isdigit(ch)){
            postfix[j++] = ch;
            postfix[j++] = ' ';
        }
        else if (ch == '('){
            pushStack(&s,ch);
        }
        else if (ch == ')'){
            while ((!isEmptyStack(&s))&&(peekStack(&s)!='('))
            {
                postfix[j++] = popStack(&s);
                postfix[j++] = ' ';
            }
            popStack(&s);
        }
        else if (isOperator(ch)){
            while ((!isEmptyStack(&s)) && (precedence(peekStack(&s)) >= precedence(ch)))
            {
                postfix[j++] = popStack(&s);
                postfix[j++] = ' ';
            }
            pushStack(&s,ch);
        }
    }
    while (!isEmptyStack(&s)){
        postfix[j++] = popStack(&s);
        postfix[j++] = ' ';
    }
    postfix[j++] = '\0';
}

double get_answer(char* postfix){
    DoubleStack s;
    init_DoubleStack(&s);
    char ch;
    int i=0;
    while((ch = postfix[i++])!='\0'){
        if (isdigit(ch)){
            pushDStack(&s,ch - '0');
        }
        else if (isOperator(ch)){
            double b = popDStack(&s);
            double a = popDStack(&s);
            switch (ch)
            {
            case '+': pushDStack(&s,a+b); break;
            case '-': pushDStack(&s,a-b); break;
            case '*': pushDStack(&s,a*b); break;
            case '/': pushDStack(&s,a/b); break;
            }
        }
    }
    return popDStack(&s);
}

int main(){
    char infix[Max_length];
    char postfix[Max_length];
    fgets(infix,Max_length,stdin);
    infix[strcspn(infix,"\n")] = '\0';

    infix_to_fontfix(infix,postfix);
    double result = get_answer(postfix);
    printf("%.2f\n",result);
    printf("%s\n",postfix);
}