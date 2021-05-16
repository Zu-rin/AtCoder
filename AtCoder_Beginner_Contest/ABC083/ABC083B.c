#include <stdio.h>

int sum(int val){
    if(val == 0)return 0;
    int ans = val % 10;
    do{
        val /= 10;
        ans += val % 10;
    }while(val > 0);
    return ans;
}

int main(void){
    int i, n, a, b, ans = 0, buf;
    scanf("%d %d %d",&n,&a,&b);
    for(i=1; i<=n; i++){
        buf = sum(i);
        if(a<=buf && buf<=b)ans += i;
    }
    printf("%d", ans);
    return 0;
}