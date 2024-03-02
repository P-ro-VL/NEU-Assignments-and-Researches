#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        vector<long long> uoc;
        for (long long i = 0; i < sqrt(n); i++)
            if (n % i == 0)
                uoc.push_back(i);

        cout << uoc.size() << endl;

        for (int k = 0; k < uoc.size(); k++)
        {
            long long i = uoc[k];
            double loga = log((n / i) + 1) / log(2);
            cout << loga;
            double intpart;
            if (modf(loga, &intpart) == 0.0)
            {
                cout << i;
                break;
            }
        }
    }

    return 0;
}