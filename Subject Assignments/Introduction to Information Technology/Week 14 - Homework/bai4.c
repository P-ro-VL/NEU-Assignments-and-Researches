#include <stdio.h>

int main(){

    int found = 0, n = 100;
    while(found == 0){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += i;
        }

        if(sum > 10000){
            printf("%d", n);
            break;
        } else {
            n++;
        }
    }

    return 0;
}