#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        nums.push_back(v);
    }

    int m[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if(i == j)
                continue;
            if(gcd(nums[i], nums[j]) == 1) {
                m[i][j] = 1;
            }else {
                m[i][j] = 0;
            }
        }

    int count = 0;
    for (int i = 0; i < n; i++) {
        int flag = 1;
        for (int j = i + 1; j < n; j++) {
            if(m[i][j] != 1) {
                flag = 0;
            }
        }
        if(flag)
            count++;
    }

    cout << n - count;

    return 0;
}