#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> fibo;
vector<ll> ways;
void initFibo() {
    ll a = 1, b = 1, tg = 0;
    while(tg < pow(10, 18)) {
        tg = a + b;
        a = b;
        b = tg;
        fibo.push_back(tg);
    }
}

bool isFibo(ll n) {
    for(ll i = 0; i < fibo.size(); i++) {
        if(fibo[i] == n) return true;
    }
    return false;
}

ll initWay(ll number) {
    int ways = 0;zz
    for(int i = 2; i <= number; i++){
        ll n = number;

        while(n % i == 0){
            nums.push_back(i);
            n /= i;
        }

        for(int z = 0; z < nums.size(); z++) {
            cout << nums[z] << "x";
        }
        bool passed = true;
        for(int j = 0; j < nums.size(); j++) {
            if(!isFibo(nums[j])) {
                passed = false;
                break;
            }
        }
        if(passed) ways++;
    }
    return ways;
}

int main() {
    initFibo();

    int t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        cout << initWay(n);
    }
}