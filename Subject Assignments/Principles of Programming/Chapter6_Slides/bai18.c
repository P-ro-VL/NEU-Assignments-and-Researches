#include <stdio.h>

long long int giaiThua[101];

void setup() {
    long long int t = 1;
    for (int i = 1; i <= 100; i++)
    {
        t *= i;
        giaiThua[i] = t;
    }
}

long long int C(int k, int n){
    return giaiThua[n] / (giaiThua[k] * giaiThua[n - k]);
}

int main() {
    setup();
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%lld", C(k,n));
}