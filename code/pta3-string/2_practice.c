#include <stdio.h>
#include <string.h>

#define MAX_TEXT 1000000
#define MAX_PATTERN 100000

void calculate_LPSArray(int *lps,int M,char *pattern){
    int i = 1;
    int length = 0;
    lps[0] = 0;

    while(i<M){
        if (pattern[i] == pattern[length]){
            length++;
            lps[i] = length;//lps不是pattern
            i++;
        }
        else{
            if (length != 0){
                length = lps[length - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMP(char *text,char *pattern){
    int N = strlen(text);
    int M = strlen(pattern);

    int lps[MAX_PATTERN];
    calculate_LPSArray(lps,M,pattern);

    int i=0,j=0;

    while(i<N){ //是小于不是小于等于
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        if(j == M){
            return i-j;
        }
        else if (i<N && text[i]!=pattern[j]){ //是小于不是小于等于
            if (j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return -1;
}

int main(){
    char text[MAX_TEXT+1];
    scanf("%s",text);

    int num;
    scanf("%d",&num);

    for (int i = 1;i<=num;i++){
        char pattern[MAX_PATTERN+1];
        scanf("%s",pattern);

        int substring_start = KMP(text,pattern);
        if (substring_start == -1){
            printf("Not Found\n");
        }
        else{
            printf("%s\n",text+substring_start);
        }
    }

    return 0;
}