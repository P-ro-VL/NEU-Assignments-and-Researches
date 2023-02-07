#include <stdio.h>

int main(){
    while(1){
        int a;
        scanf("%d", &a);
        if(a >= 10 && a <= 100){
            for(int i = 1; i <= a; i++){
                if(a % i == 0)
                printf("%d ", i);
            }
            break;
        }
    }

    return 0;
}