#include <bits/stdc++.h>

using namespace std;

long long fibonacii[9999999];

void prequisite() {
    memset(fibonacii, 0, 9999999);
    int a = 1, b = 1;
    for (long long i = 0; i < 9999999; i++) {
        int tg = a + b;
        a = b;
        b = tg;
        fibonacii[tg] = 1;
    }
}

int solve(long long n) {
    int count = fibonacii[n] == 1;
    int duyet[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int c = 0;
    for (int i = 2; i <= 9; i++) {
        if(n % i == 0) {
            if(fibonacii[i] && fibonacii[n / i]) {
                count++;
            }else{
                count += solve(n / i);
            }
            c++;
        }
    }
    return count - (c - 1);
}

int main() {
    prequisite();

    cout << solve(40);
}

