#include <stdio.h>

int main(void){
    int m;
    scanf("%d", &m);
    if(m < 100) printf("00\n");
    else if(m <= 5000) printf("%02d\n",m/100);
    else if(m <= 30000) printf("%02d\n",m/1000 + 50);
    else if(m <= 70000) printf("%02d\n",(m - 30000)/5000 + 80);
    else printf("89\n");
    return 0;
}