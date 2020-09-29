#include <stdio.h>

int main(void){
    float dis, dlist[15]={337.5, 562.5, 787.5, 1012.5, 1237.5, 1462.5, 1687.5, 1912.5, 2137.5, 2362.5, 2587.5, 2812.5, 3037.5, 3262.5, 3487.5};
    int i, deg, dir, ans, ws[11]={16,34,55,80,108,139,172,208,245,285,327};
    char a[15][4] = {"NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};
    scanf("%d %f",&deg,&dis);
    dir = (int)(dis + 3.0)/6.0;
    if(dir < 3){
        printf("C 0\n");
        return 0;
    }else for(i=0,ans=1; i < 11 && ws[i] <= dir; i++)ans++;
    if(deg < 112.5 || 3487.5 <= deg){
        printf("N %d\n",ans);
        return 0;
    }
    else for(i=0; i < 15; i++)if(deg < dlist[i]){
        printf("%s %d\n",a[i],ans);
        return 0;
    }
}