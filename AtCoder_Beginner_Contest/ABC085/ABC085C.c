#include <stdio.h>

int main(void){
    int n, y, a=0, b, c=0;
    scanf("%d %d", &n, &y);
    y /= 1000;
    b = n;
    while(b > 0){
        if(y == 5*b){
            y = 0;
            break;
        }else if(y < 5*b){
            b--; c++;
            y--;
        }else{
            a++; b--;
            y -= 10;
        }
    }
    if(y != 0)printf("-1 -1 -1");
    else printf("%d %d %d", a, b, c);
    return 0;
}