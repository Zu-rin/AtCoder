#include <stdio.h>

int main(void){
    int i;
    float ans, a[6];
    for(i=0; i<6; i++) scanf("%f",&a[i]);
    a[0] -= a[4];
    a[2] -= a[4];
    a[1] -= a[5];
    a[3] -= a[5];
    if((ans = (a[0]*a[3]) - (a[1]*a[2])) < 0)ans *= -1;
    printf("%.1f", ans/2);
    return 0;
}