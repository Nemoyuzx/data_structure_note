#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define coffee 3

void swap(int a[], int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
void print(int a[], int l, int r)
{
    printf("Qsort(%d,%d):", l - 1, r - 1);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
}
void insert(int a[], int left, int right)
{
    int i, j, tmp;
    for (i = left + 1; i <= right; i++)
    {
        tmp = a[i];
        for (j = i; j > left && a[j - 1] > tmp; j--)
        {
            a[j] = a[j - 1];
        }
        a[j] = tmp;
    }
    printf("insert(%d,%d):", left - 1, right - left + 1);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
}
void median(int a[], int left, int right)
{
    int mid = (left + right) / 2;
    if (a[mid] < a[left])
        swap(a, left, mid);
    if (a[mid] > a[right])
        swap(a, right, mid);
    if (a[mid] < a[left])
        swap(a, left, mid);
    swap(a, mid, right - 1);
}
void quick_sort(int a[], int pos, int left, int right)
{
    if (right - left + 1 <= coffee)
    {
        insert(a, left, right);
    }
    else
    {
        if (pos != -1)
        {
            swap(a, pos, right);
            int pivot = a[right];
            int l = left - 1, r = right;
            while (1)
            {
                while (a[++l] < pivot)
                    ;
                while (a[--r] > pivot)
                    ;
                if (l >= r)
                    break;
                else
                    swap(a, l, r);
            }
            swap(a, l, right);
            print(a, left, right);
            quick_sort(a, -1, left, l - 1);
            quick_sort(a, -1, l + 1, right);
        }
        else
        {
            median(a, left, right);
            int pivot = a[right - 1];
            int l = left, r = right - 1;
            while (1)
            {
                while (a[++l] < pivot)
                    ;
                while (a[--r] > pivot)
                    ;
                if (l >= r)
                    break;
                else
                    swap(a, l, r);
            }
            swap(a, l, right - 1);
            print(a, left, right);
            quick_sort(a, -1, left, l - 1);
            quick_sort(a, -1, l + 1, right);
        }
    }
}
int main()
{
    int pos, num = 10;
    scanf("%d", &pos);
    int a[11] = {0, 49, 38, 65, 97, 76, 13, 27, 50, 2, 8};
    quick_sort(a, pos + 1, 1, 10);
    return 0;
}