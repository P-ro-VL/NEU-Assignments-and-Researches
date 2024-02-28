#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cout << "===============";
    while (t--)
    {
        long long n;
        cin >> n;

        vector<long long> uoc;
        for (int i = 1; i < sqrt(n); i++)
            if (n % i == 0)
                uoc.push_back(i);

        for (int z = uoc.size() - 1; z >= 0; z--)
        {
            int i = uoc[z];
            double loga = log2((n / i) + 1);
            double intpart;
            if (modf(loga, &intpart) == 0.0)
            {
                cout << i << " " << loga << endl;
                break;
            }
        }
    }

    return 0;
}