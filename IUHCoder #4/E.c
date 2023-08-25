#include <stdio.h>
#include <math.h>
#include <string.h>

int solve(int n) {
    int powArray[10000];
    for (int i = 0; i < 10000; i++)
        powArray[i] = 0;

    int calculated = 0;

    for (int exp = sqrt(n); exp >= 2; exp--) {
        if(calculated >= n)
            break;
        int powx = 2;
        int verified = 0;

        while(calculated + pow(exp, powx) <= n) {
            powArray[exp] = powx;
            powx++;
            verified = 1;
        }

        if(verified) {
            calculated = calculated + lround(pow(exp, powx - 1));
        }
    }

    int sum = 0;
    int total = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if(powArray[i] > 0) {
            sum += powArray[i];
            printf("%d^%d + ", i, powArray[i]);
            total += lround(pow(i, powArray[i]));
        }
    }

    if(n - calculated >= 1)
        sum += 2 * (n - calculated);

    printf("\n%d", sum);
}

int main() {
    int n;
    scanf("%d", &n);

    solve(n);
}