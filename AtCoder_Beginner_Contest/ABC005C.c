#include <stdio.h>

int main(void){
    int i, j=0, t, p, c;
    scanf("%d %d",&t,&p);
    int a[p];
    for(i=0; i<p; i++) scanf("%d",&a[i]);
    scanf("%d",&c);
    int b[c], rem = p-c;
    for(i=0; i<c; i++) scanf("%d",&b[i]);
    i=0;
    for(; j<c; j++){
        if(b[j] < a[i]){
            printf("no\n");
            return 0;
        }
        while(a[i++]+t < b[j]){
            if(p == i || --rem < 0){
                printf("no\n");
                return 0;
            }
        }
    }
    printf("yes\n");
    return 0;
}