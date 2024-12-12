#include <stdio.h>
#include <string.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(",");
        }
    }
    printf(",\n");
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printArray(arr, n);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[20];
    char input[100];
    scanf("%s", input);

    int i = 0;
    char *token = strtok(input, ",");
    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, ",");
    }

    insertionSort(arr, n);

    return 0;
}
