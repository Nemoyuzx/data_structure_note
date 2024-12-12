#include <stdio.h>
#include <string.h>

#define MAX_LEN 10005

int main() {
    char A[MAX_LEN], B[MAX_LEN];
    int flag[128] = {0};  // 用于标记字符是否出现在B中，ASCII码一共128个字符

    // 读取字符串 A 和 B
    fgets(A, MAX_LEN, stdin);
    fgets(B, MAX_LEN, stdin);

    // 标记字符串 B 中出现的字符
    for (int i = 0; B[i] != '\0'; i++) {
        flag[(int)B[i]] = 1;
    }

    // 输出字符串 A 中不在 B 中的字符
    for (int i = 0; A[i] != '\0'; i++) {
        if (flag[(int)A[i]] == 0) {
            putchar(A[i]);
        }
    }

    return 0;
}