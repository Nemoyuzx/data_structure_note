#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;  // 假设当前元素是最小的
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;  // 找到更小的元素
            }
        }
        
        // 如果最小元素不是当前元素，则交换
        if (minIdx != i) {
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }

        // 输出当前排序步骤
        for (int k = 0; k < n; k++) {
            printf("%d", arr[k]);
            if (k != n - 1) {
                printf(",");
            }
        }
        printf(",\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);  // 输入元素的个数
    int arr[n];
    
    // 输入数组元素
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            scanf("%d", &arr[i]);  // 最后一个元素
        } else {
            scanf("%d,", &arr[i]);  // 读取逗号分隔的整数
        }
    }
    
    selectionSort(arr, n);
    
    return 0;
}
