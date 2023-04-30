#include <stdio.h>

int main() {
    long long int n;
    scanf("%lld", &n);

    long long int t = 0;
    while(n > 0){
        t += n % 10;
        n /= 10;
    }

    printf("%lli", t);
}