#include <stdio.h>

int BC(int b, int c, int x){
    int pat=0;
    if(x == 0)return 1;
    while(b>=0 && x>=0){
        if(x <= 50*c)pat++;
        x-=100;
        b--;
    }
    return pat;
}

int main(void){
    int i, coin[3], x, pat=0;
    for(i=0; i<3; i++)scanf("%d", &coin[i]);
    scanf("%d", &x);
    for(; coin[0]>=0 && x>=0; coin[0]--, x-=500){
        pat+=BC(coin[1], coin[2], x);
    }
    printf("%d",pat);
    return 0;
}