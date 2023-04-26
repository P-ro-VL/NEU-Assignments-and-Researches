#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int k = n;
    while(k >= 10){
        int sum = 0;
        int h = k;
        while(h > 0){
            sum += h % 10;
            h /= 10;
        }
        k = sum;
    }
    printf("%d", k);
}