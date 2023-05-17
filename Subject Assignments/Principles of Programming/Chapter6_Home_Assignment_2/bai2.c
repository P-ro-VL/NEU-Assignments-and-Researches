#include <stdio.h>

int fibonacci(int n);
int sumFibonacci(int n);

int main() {
    int n;
    scanf("%d", &n);
    printf("%d %d", fibonacci(n), sumFibonacci(n));
}

int fibonacci(int n) {
    if(n == 1 || n == 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int sumFibonacci(int n){
    if(n <= 1)
        return 0;
    return fibonacci(n) + sumFibonacci(n - 2);
}