#include <stdio.h>

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    if(n%k == 0)printf("0");
    else printf("1");
    return 0;
}