#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 20

// 获取数字的某一位的值
int get_digit(int num, int digit_position) {
    return (num / digit_position) % 10;
}

// 基数排序的一个 pass
void counting_sort(int arr[], int n, int digit_position) {
    int output[n];
    int count[10] = {0};

    // 统计每个桶的数量
    for (int i = 0; i < n; i++) {
        int digit = get_digit(arr[i], digit_position);
        count[digit]++;
    }

    // 累加 count 数组
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 从后向前填充 output 数组，以保持稳定性
    for (int i = n - 1; i >= 0; i--) {
        int digit = get_digit(arr[i], digit_position);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // 将排序结果复制回原数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// 打印数组
void print_array(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(",");
        }
    }
    printf(",\n");
}

int main() {
    // 输入解析
    char input[200];
    int arr[MAX_NUM];
    int n = 0;
    int pass_num;

    // 第一行输入，数字序列
    fgets(input, sizeof(input), stdin);
    char *token = strtok(input, ",");
    while (token != NULL) {
        arr[n++] = atoi(token);
        token = strtok(NULL, ",");
    }

    // 第二行输入，步数
    scanf("%d", &pass_num);

    // 基数排序的最大位数
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    int max_digit_position = 1;
    while (max_val / max_digit_position > 0) {
        max_digit_position *= 10;
    }

    // 执行基数排序并打印每一步的结果
    for (int digit_position = 1; digit_position < max_digit_position; digit_position *= 10) {
        counting_sort(arr, n, digit_position);
        pass_num--;
        if (pass_num == 0) {
            print_array(arr, n);
            break;
        }
    }

    return 0;
}
