#include <stdio.h>

int main() {
    long n;
    scanf("%d", &n);

    int t = 0;
    while(n > 0){
        t += n % 10;
        n /= 10;
    }

    printf("%ld", t);
}