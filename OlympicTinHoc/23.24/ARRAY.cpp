#include <bits/stdc++.h>

using namespace std;

map<int, int> phantich(long long n) {
    long long N = n;
    map<int, int> m;
    for(int i = 2; i <= N; i++){
        while(N % i == 0){
            m[i]++;
            N /= i;
        }
    }
    return m;
}

bool thoaman(long long n, long long m) {
    map<int, int> map1 = phantich(n);
    map<int, int> map2 = phantich(m);

    bool bypass = true;
    for(auto entry : map1) {
        if(map2.find(entry.first) != map2.end() && map2.size() == map1.size()) {
        } else {
            bypass = false;
            break;
        }
    }
    return bypass;
}

int main() {
    int n;
    cin >> n;

    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if(arr[i] == 1)
            continue;
        for (int j = i + 1; j < n; j++) {
            if(i == j || arr[j] == 1) continue;

            if(thoaman(arr[i], arr[j]))
                count++;
        }
    }

    cout << count;

    return 0;
}