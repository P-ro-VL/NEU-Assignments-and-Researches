#include <bits/stdc++.h>
#include <string>

using namespace std;

bool isSpecialString(char *string, int fromIndex, int endIndex) {
    char digits[128];
    memset(digits, 0, 128);
    for (int i = fromIndex; i < endIndex; i++) {
        digits[string[i]]++;
    }
    int max = digits[48];
    int count = 0;
    for (int i = 48; i <= 57; i++) {
        if(digits[i] != 0) {
            count++;
            if(digits[i] > max) {
                max = digits[i];
            }
        }
    }
    return max <= count;
}

long long count(char *value, int n) {
    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if(!isSpecialString(value, i, j + 1))
                continue;
            count++;
        }
    }
    return count + n;
}

int main() {
    int test;
    cin >> test;

    while(test--) {
        int n;
        cin >> n;
        char value[n];
        cin >> value;
        cin.ignore(1);

        cout << count(value, n) << endl;
    }
}