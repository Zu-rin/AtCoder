#include <stdio.h>

int main(void){
    int i,num,ans=0;
    scanf("%d", &num);
    unsigned int a[num];
    for(i=0; i<num; i++) scanf("%d", &a[i]);
    while(1){
        i=0;
        while(i<num){
            if(a[i] & 0x1)break;
            a[i] = a[i] >> 1;
            i++;
        }
        if(i!=num)break;
        ans++;
    }
    printf("%d", ans);
    return 0;
}