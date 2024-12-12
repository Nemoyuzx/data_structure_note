#include <stdio.h>
#define Cutoff 3

// 函数声明
void Quicksort(int A[], int N, int initialPivotIndex);
void Qsort(int A[], int Left, int Right);
int Median3(int A[], int Left, int Right);
void InsertionSort(int A[], int Left, int Right);
void Swap(int *a, int *b);
void PrintArray(const char *msg, int A[], int Left, int Right);

int main() {
    int A[] = {20, 38, 24, 23, 26, 32, 21, 29, 38};
    int N = (sizeof(A) / sizeof(A[0]))-1;
    int pivotIndex;

    // 输入第一个枢轴的索引（从0开始）
    scanf("%d", &pivotIndex);

    // 执行快速排序，传入用户指定的初始主元索引
    Quicksort(A, N, pivotIndex);

    return 0;
}

// 快速排序驱动函数
void Quicksort(int A[], int N, int initialPivotIndex) {
    // 将用户指定的初始主元移动到数组最右端
    int Pivot = A[initialPivotIndex];

    if (initialPivotIndex >= 0 && initialPivotIndex < N - 1) {
        Swap(&A[initialPivotIndex], &A[N - 1]);
    }
    
    int i, j;
    i = -1;
    j = N - 1;

    for (;;) {
        while (A[++i] < Pivot) {
            //printf("i = %d\n", i);
        }  // 从左扫描找到第一个 >= Pivot 的元素
        while (A[--j] > Pivot) {
            //printf("j = %d\n", j);
        }  // 从右扫描找到第一个 <= Pivot 的元素
        if (i < j) {
            //printf("Swap %d and %d\n", A[i], A[j]);
            Swap(&A[i], &A[j]);    // 交换这两个元素
        } else {
            break;  // 如果 i >= j，则分区完成
        }
    }

    Swap(&A[i], &A[N - 1]); // 将枢轴放到正确的位置

    int pivotPosition = i;  // 记录第一次分区的结果
    int Left = 0, Right = N - 1;

    // 打印第一次分区的结果
    PrintArray("Qsort", A, Left, Right);

    // 递归处理左右子数组
    Qsort(A, Left, pivotPosition - 1);
    Qsort(A, pivotPosition + 1, Right);
}

// 递归快速排序
void Qsort(int A[], int Left, int Right) {
    //打印左右边界，用于调试，可注释掉或删除
    //printf("Left = %d, Right = %d\n", Left, Right);
    if (Left + Cutoff <= Right) {
        // 使用“三数中值法”选择枢轴
        int Pivot = Median3(A, Left, Right);
        //printf("Pivot = %d\n", Pivot);
        int i = Left, j = Right - 1;

        Swap(&A[Left], &A[Right - 1]); // 将枢轴藏到右端

        i = Left-1;
        j = Right ;

        // 分区操作：从两端向中间扫描，并交换不符合条件的值
        for (;;) {
            //printf("i = %d, j = %d\n", i, j);
            while (A[++i] < Pivot) {
                //printf("change:i = %d\n", i);
            }  // 从左扫描找到第一个 >= Pivot 的元素
            while (A[--j] > Pivot) {
                //printf("change:j = %d\n", j);
            }  // 从右扫描找到第一个 <= Pivot 的元素
            if (i < j) {
                //printf("Swap %d and %d\n", A[i], A[j]);
                Swap(&A[i], &A[j]);    // 交换这两个元素

            } else {
                break;  // 如果 i >= j，则分区完成
            }
        }

        Swap(&A[i], &A[Right - 1]); // 将枢轴放到正确的位置

        // 打印当前快速排序的中间结果
        PrintArray("Qsort", A, Left, Right);

        // 递归处理左右部分
        //printf("Qsort(Left:%d,i:%d)\n", Left, i-1);
        Qsort(A, Left, i-1);
        //printf("Qsort(i:%d,Right:%d)\n", i+1, Right);
        Qsort(A, i+1, Right);
    } else {
        // 对小数组使用插入排序
        InsertionSort(A, Left, Right+1);
        PrintArray("insert", A, Left, Right-Left+1);
    }
}

// 三数中值法返回pivot值（不改变数组）
int Median3(int A[], int Left, int Right) {
    int Center = (Left + Right) / 2;
    if (A[Left] > A[Center]) {
        Swap(&A[Left], &A[Center]);
    }
    if (A[Left] > A[Right]) {
        Swap(&A[Left], &A[Right]);
    }
    if (A[Center] > A[Right]) {
        Swap(&A[Center], &A[Right]);
    }

    // 将枢轴藏到右端
    Swap(&A[Center], &A[Right - 1]);
    return A[Right-1];
    
}

// 插入排序
void InsertionSort(int A[], int Left, int Right) {
    int i, j, Tmp;
    for (i = Left + 1; i <= Right; i++) {
        Tmp = A[i];
        for (j = i; j > Left && A[j - 1] > Tmp; j--) {
            A[j] = A[j - 1];
        }
        A[j] = Tmp;
    }
}

// 交换两个元素
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 打印数组
void PrintArray(const char *msg, int A[], int Left, int Right) {
    printf("%s(%d,%d):", msg, Left, Right);
    for (int i = 0; i < 10; i++) { // 假设数组大小固定为10
        printf("%d", A[i]);
        if (i < 9) printf(",");
    }
    printf(",\n");
}