#include <stdio.h>

int main(void){
    int i, n, x, y, a[11] = {1,2,3,4,5,6,1,2,3,4,5};
    scanf("%d",&n);
    n %= 30;
    x = n/5;
    for(i=x+1, y=n%5+x; i<=y; i++)printf("%d",a[i]);
    printf("%d",a[x]);
    for(; i<x+6; i++)printf("%d",a[i]);
    return 0;
}