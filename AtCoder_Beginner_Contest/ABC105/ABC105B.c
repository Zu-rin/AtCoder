#include <stdio.h>

int main(void){
    int n, ans;
    scanf("%d", &n);
    for(; n>=0; n-=7){
        if(n%4==0 || n==0){
            printf("Yes");
            return 0;;
        }
    }
    printf("No");
    return 0;
}