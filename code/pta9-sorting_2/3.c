#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 将子树以s为根对范围[0..m]调整为最大堆
void Heapify(int arr[], int s, int m) {
    int root = arr[s];
    int child = 2 * s + 1; // 左孩子下标
    
    while (child <= m) {
        // 如果右孩子存在且右孩子值更大，则将child指向右孩子
        if (child < m && arr[child] < arr[child + 1]) {
            child++;
        }
        // 如果根已大于等于最大子节点，堆特性已满足，停止向下过滤
        if (root >= arr[child]) {
            break;
        }
        // 将子节点上移
        arr[s] = arr[child];
        s = child;
        child = 2 * s + 1;
    }
    arr[s] = root;
}

// 堆排序函数，step表示当堆排序进行到第step次交换后输出中间状态
void HeapSort(int arr[], int length, int step) {
    // 1. 建立初始最大堆
    for (int i = length / 2 - 1; i >= 0; i--) {
        Heapify(arr, i, length - 1);
    }

    int stepCount = 0;

    // 2. 逐步将堆顶(最大值)和未排序区最后一个元素交换，然后堆的有效长度-1
    for (int i = length - 1; i > 0; i--) {
        

        // 这完成一次选出最大元素的过程
        stepCount++;
        if (stepCount == step) {
            for (int k = 0; k < length; k++) {
                printf("%d,", arr[k]);
            }
            return;
        }

        // 交换堆顶元素与未排序区最后一个元素
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 对堆顶进行向下过滤，使其再次成为最大堆(范围[0..i-1])
        Heapify(arr, 0, i - 1);
    }
}

int main() {
    char input[500];
    int step;
    int arr[100];
    
    // 读取输入序列
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 1; 
    }

    // 去掉行末换行符
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

    // 读取step
    if (scanf("%d", &step) != 1) {
        return 1;
    }

    // 调用堆排序，并在第step次交换后输出状态
    HeapSort(arr, length, step);
    

    return 0;
}
