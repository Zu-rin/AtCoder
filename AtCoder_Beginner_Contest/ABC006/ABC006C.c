#include <stdio.h>

int main(void){
    int a = 0, b, c = 0, m;
    scanf("%d %d",&b,&m);
    for(; b>=0; b--){
        if(m == 3*b) break;
        else if(m < 3*b){
            a++;
            m -= 2;
        }else{
            c++;
            m -= 4;
        }
    }
    if(b < 0) printf("-1 -1 -1\n");
    else printf("%d %d %d\n",a,b,c);
    return 0;
}