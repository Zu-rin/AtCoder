#include <stdio.h>
#include <string.h>

int search(char *a){
    if(a[0] == '\0') return 1;
    int ans = 0;
    if((strstr(a,"dream") - a) == 0){
        ans += search(&a[5]);
        if(a[5] == 'e' && a[6] == 'r') ans += search(&a[7]);
    }
    if((strstr(a,"erase") - a) == 0){
        ans += search(&a[5]);
        if(a[5] == 'r') ans += search(&a[6]);
    }
    if(ans > 0) return 1;
    else return 0;
}

int main(void){
    char s[100001];
    scanf("%s",&s);
    if(search(s) > 0) printf("YES");
    else printf("NO");
    return 0;
}