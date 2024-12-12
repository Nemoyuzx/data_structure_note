#include <stdio.h>
#include <string.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    // 合并两个数组
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    // 如果第一个数组还有剩余
    while (i < size1) {
        result[k++] = arr1[i++];
    }

    // 如果第二个数组还有剩余
    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

void parseInput(char input[], int array[], int *size) {
    int len = strlen(input);
    *size = 0;
    int temp = 0;
    int hasNumber = 0;

    for (int i = 0; i < len; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            temp = temp * 10 + (input[i] - '0');
            hasNumber = 1;
        } else if ((input[i] == ',' || input[i] == '\n') && hasNumber) {
            array[(*size)++] = temp;
            temp = 0;
            hasNumber = 0;
        }
    }
    // 添加最后一个数字
    if (hasNumber) {
        array[(*size)++] = temp;
    }
}

int main() {
    char input1[500], input2[500];
    int arr1[100], arr2[100], result[200];
    int size1, size2;

    // 读取两行输入
    fgets(input1, sizeof(input1), stdin);
    fgets(input2, sizeof(input2), stdin);

    // 解析输入
    parseInput(input1, arr1, &size1);
    parseInput(input2, arr2, &size2);

    // 合并数组
    mergeArrays(arr1, size1, arr2, size2, result);

    // 输出结果
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d,", result[i]);
    }

    return 0;
}
