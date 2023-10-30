#include <bits/stdc++.h>

using namespace std;

long long solve(long long n) {
    return 1 + ((n * (n - 3) * (n * n - 3 * n + 14)) / 24);
}

int main() {
    long long n;
    cin >> n;

    cout << solve(n) % 987654321;
}