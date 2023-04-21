#include <stdio.h>

int main() {
    int number = 0;
    while(1){
        int tong = (1 + number) * number / 2;
        if(tong > 10000){
            printf("%d", number);
            break;
        }else{
            number++;
        }
    }
}