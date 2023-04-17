#include <stdio.h>

int main(){
    int bits[8];

    int n;
    scanf("%d", &n);
    for (int i = 7; i >= 0; i--){
        bits[i] = n % 2;
        n /= 2;
    }

    for (int i = 0; i < 8; i ++)
        printf("%d", bits[i]);
}