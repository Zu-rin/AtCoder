#include <stdio.h>

int main(void){
    int i=0, num, Tag;
    scanf("%d",&num);
    unsigned int all Coins[num], Div_Num[num];
    for(; i < num; i++){
        scanf("%d", &Tag);
        Coins[i] = Tag;
        Div_Num[i] = 0;
        for(j = 0; j < i; j++){
            if(Tag % Coins[j] == 0) Div_num[i]++;
        }
    }


}