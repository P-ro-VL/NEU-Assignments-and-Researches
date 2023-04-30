#include <stdio.h>

unsigned long long int giaiThua[101];

void setup() {
    unsigned long long int t = 1;
    for (int i = 1; i <= 50; i++)
    {
        t *= i;
        giaiThua[i] = t;
    }
}

unsigned long long int C(int k, int n){
    return giaiThua[n] / (giaiThua[k] * giaiThua[n - k]);
}

int main() {
    setup();
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%llu", C(k,n));
}