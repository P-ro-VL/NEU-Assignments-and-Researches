#include <stdio.h>

long long int giaiThuaCach(int n){
    long long int t = 1;
    for (int i = (n % 2 == 0 ? 2 : 3); i <= n; i += 2){
        t *= i;
    }
    return t;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", giaiThuaCach(n));
}