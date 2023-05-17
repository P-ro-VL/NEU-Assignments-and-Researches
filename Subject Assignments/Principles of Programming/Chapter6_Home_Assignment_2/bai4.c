#include <stdio.h>

float solve(int n, int origin);

int main() {
    int n;
    scanf("%d", &n);
    printf("%f", solve(n, n));
}

float solve(int n, int origin){
    if(n <= 0)
        return 0;
    return (n*1.0 / origin) + solve(n - 1, origin);
}