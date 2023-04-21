#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int tong = 0;
    for (int i = 1; i <= n; i++)
        tong += i;
    printf("%d", tong);
}