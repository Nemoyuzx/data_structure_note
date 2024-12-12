#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 将子树以 s 为根对范围 [0..m] 调整为最大堆
void Heapify(int arr[], int s, int m) {
    int root = arr[s];
    int child = 2 * s + 1; // 左孩子下标
    
    while (child <= m) {
        if (child < m && arr[child] < arr[child + 1]) {
            child++;
        }
        if (root >= arr[child]) {
            break;
        }
        arr[s] = arr[child];
        s = child;
        child = 2 * s + 1;
    }
    arr[s] = root;
}

// 堆排序函数，step 表示第 step 次交换后输出中间状态
void HeapSort(int arr[], int length, int step) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        Heapify(arr, i, length - 1);
    }

    int stepCount = 0;
    for (int i = length - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        stepCount++;
        if (stepCount == step) {
            for (int k = 0; k < length; k++) {
                printf("%d", arr[k]);
                if (k != length - 1) printf(",");
            }
            printf("\n");
            return;
        }

        Heapify(arr, 0, i - 1);
    }
}

int main() {
    char input[500];
    int step;
    int arr[100];

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 1; 
    }

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    char *token = strtok(input, ",");
    int index = 0;
    while (token && index < 100) {
        arr[index++] = atoi(token);
        token = strtok(NULL, ",");
    }
    int length = index;

    if (scanf("%d", &step) != 1 || step < 1) {
        return 1;
    }

    for (int i = 0; i < length; i++) {
        HeapSort(arr, length, i);
    }
    return 0;
}
