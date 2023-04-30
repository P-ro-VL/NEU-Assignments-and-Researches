#include <stdio.h>

int main() {
    long long int n;
    scanf("%lld", &n);

    long long int k = n;
    while(k >= 10){
        long long int sum = 0;
        long long int h = k;
        while(h > 0){
            sum += h % 10;
            h /= 10;
        }
        k = sum;
    }
    printf("%lld", k);
}