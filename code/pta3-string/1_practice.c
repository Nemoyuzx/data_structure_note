#include <stdio.h>
#include <string.h>

#define MAX 10005

int main(){
    char A[MAX], B[MAX];
    int ASCII[128]={0};

    fgets(A,MAX,stdin);//注意A，B和stdin的顺序
    fgets(B,MAX,stdin);

    for (int i=0;B[i] != '\0';i++){
        ASCII[(int)B[i]] = 1;
    }

    for (int i=0;A[i] != '\0';i++){
        if (ASCII[(int)A[i]] == 0){
            putchar(A[i]);//注意putchar
        }
    }

    return 0;
}