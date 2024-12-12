#include <stdio.h>
#include <string.h>
#define MAX_STRING_LEN 1000000
#define MAX_PATTERN_LEN 100000

// 构造部分匹配表（即 next 数组）
void computeLPSArray(char* pattern, int M, int* lps) {
    int length = 0;  // 最长相等前后缀的长度
    lps[0] = 0;      // lps[0] 总是 0
    int i = 1;
    while (i < M) {  // 从第二个字符开始计算
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP 搜索算法
int KMPSearch(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);

    // 创建 lps 数组，存储部分匹配值
    int lps[MAX_PATTERN_LEN];
    computeLPSArray(pattern, M, lps);

    int i = 0;  // text 的索引
    int j = 0;  // pattern 的索引
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            // 找到匹配，返回匹配的起始位置
            return i - j;
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }

    return -1;  // 未找到匹配
}

int main() {
    char string[MAX_STRING_LEN + 1];
    int n;

    // 读取输入的主字符串
    scanf("%s", string);

    // 读取待匹配的模式串个数
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char pattern[MAX_PATTERN_LEN + 1];
        scanf("%s", pattern);

        int position = KMPSearch(pattern, string);
        if (position != -1) {
            // 输出从找到的位置开始的子串
            printf("%s\n", string + position);
        } else {
            printf("Not Found\n");
        }
    }

    return 0;
}