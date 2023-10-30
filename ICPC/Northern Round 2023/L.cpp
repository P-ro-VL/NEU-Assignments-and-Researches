#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MAX = 5000001;

ll p[MAX];
void sangnt(){
    for(ll i = 0; i <= 5000000; i++)p[i] = 1;
    p[0] = p[1] = 0;
    for(ll i = 2; i <= sqrt(5000000); i++){
        if(p[i]){
            for(ll j = i * i; j <= 5000000; j += i){
                p[j] = 0;
            }
        }
    }
}

ll phi(ll n)
{
    ll res = n;

    for (ll i=0; p[i]*p[i] <= n; i++)
    {
        if (n % p[i]== 0)
        {
            res -= (res / p[i]);
            while (n % p[i]== 0)
                n /= p[i];
        }
    }

    if (n > 1)
        res -= (res / n);
    return res;
}

int main() {
    sangnt();

    ll a, b;
    cin >> a >> b;

    ll sum = 0;
    for(int i = 1; i <= b; i++) {
        sum += phi(a*i) % 998244353;
    }

    cout << sum % 998244353;
}