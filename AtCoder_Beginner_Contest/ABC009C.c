#include <stdio.h>
#include <string.h>

void swap(char Str[], int l, int r){
    char buf;
    buf = Str[l];
    Str[l] = Str[r];
    Str[r] = buf;
    return;
}

int main(void){
    int Cnum, limit;
    scanf("%d %d", &Cnum, &limit);
    char Str[Cnum+1], Ans[Cnum], Min;
    scanf("%s", &Str);
    for(Min = 0, i = 1; i < Cnum; i++){
        if(Str[i] < Min)
            Min = Str[i];
    }
    
}