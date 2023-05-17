#include <stdio.h>
#include <math.h>

float solve(int n);
float squareSum(int n);

int main() {
    int n;
    scanf("%d", &n);
    printf("%f", solve(n));
}

float solve(int n){
    return sqrt(squareSum(n));
}

float squareSum(int n){
    if(n == 1)
        return 1;
    return pow(n, 2) + squareSum(n - 1);
}