#include <stdio.h>
#include <stdlib.h>
int main(void){
    int n;
    scanf("%d",&n);
    int i, j, t[n+1], x[n+1], y[n+1], disp, tm;
    t[0] = 0;  x[0] = 0;  y[0] = 0;
    for(i=1; i<=n; i++) scanf("%d %d %d",&t[i],&x[i],&y[i]);
    for(i=0,j=1; j<=n; i++,j++){
        disp = abs(x[j]-x[i]) + abs(y[j]-y[i]);
        if(disp > (tm = t[j] - t[i]) || ((tm-disp) % 2) != 0){
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}