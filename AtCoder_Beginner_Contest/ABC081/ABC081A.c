#include <stdio.h>

int main(void){
    int i=0,num=0;
    char s[4];
    scanf("%s", &s);
    while(i<4) if(s[i++] == '1')num++;
    printf("%d", num);
    return 0;
}