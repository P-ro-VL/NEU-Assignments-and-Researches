#include <stdio.h>
#include <math.h>

float solve(int n);

int main() {
    int n;
    scanf("%d", &n);
    printf("%f", solve(n));
}

float solve(int n){
    if(n == 1)
        return sqrt(3);
    return sqrt(3.0 + solve(n - 1));
}

