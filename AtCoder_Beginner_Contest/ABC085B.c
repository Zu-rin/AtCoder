#include <stdio.h>

void qsort(int a[], int first, int last){
    if(first >= last)return;
    int pv = a[first], head = first+1, end = last, buf;
    while(1){
        while(head < end && pv <= a[head]) head++;
        while(head < end && pv >= a[end]) end--;
        if(head == end)break;
        buf = a[head];
        a[head] = a[end];
        a[end] = buf;
    }
    if(a[head]<pv) head--;
    a[first] = a[head];
    a[head] = pv;
    qsort(a,first,head-1);
    qsort(a,head+1,last);
    return;
}

int main(void){
    int n, i=0;
    scanf("%d",&n);
    int ans=n, a[n];
    for(; i<n; i++) scanf("%d",&a[i]);
    qsort(a, 0, n-1);
    for(i=0; i<n-1; i++){
        if(a[i] == a[i+1])ans--;
    }
    printf("%d",ans);
    return 0;
}