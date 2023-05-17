#include <stdio.h>

float solve(int n);

int main() {
    int n;
    scanf("%d", &n);
    printf("%f", solve(n));
}

float solve(int n){
    if(n == 1)
        return 0.5;
    return (1.0 / (n * (n + 1.0))) + solve(n - 1);
}