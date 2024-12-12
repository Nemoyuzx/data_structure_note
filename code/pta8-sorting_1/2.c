#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(",");
        }
    }
    printf(",\n");
}

void shellSort(int arr[], int n) {
    // Using Shell increment sequence with floor division
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform gapped insertion sort
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        printArray(arr, n);  // Print intermediate result
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[20];
    for (int i = 0; i < n; i++) {
        scanf("%d,", &arr[i]);
    }

        shellSort(arr, n);

    return 0;
}
