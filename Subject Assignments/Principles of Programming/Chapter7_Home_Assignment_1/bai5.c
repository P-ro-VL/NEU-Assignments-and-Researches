#include <stdio.h>

int main() {
    int f = 1;
    int n, *p;
    scanf("%d", &n);
    p = &n;

    for (int i = 1; i <= *p; i++){
        f *= i;
    }

    printf("Factorial: %d", f);
}