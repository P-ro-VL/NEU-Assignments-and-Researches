#include <bits/stdc++.h> 

using namespace std;

void traces(int n, int W, vector <vector<int>> &dp, vector<int> &weights, vector<int> &values)
{
    vector<int> picked_items;
    while (n > 0)
    {
        if (dp[n][W] == dp[n - 1][W])
            --n;
        else 
        {
            picked_items.push_back(n);
            W -= values[n];
            --n;
        }
    }

    cout << picked_items.size() << endl;
    for (int i = picked_items.size() - 1; i >= 0; --i)
        cout << picked_items[i] + 1 << ' ';
}

void solve(int n, int W, vector<int> &weights, vector<int> &values)
{
    vector <vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= W; ++j)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= weights[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i]] + values[i]);
        }

    traces(n, W, dp, weights, values);
}

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> weights;
    vector<int> values;

    for (int i = 1; i <= n; i++) {
        int _w;
        cin >> _w;

        weights.push_back(_w);
    }

    for (int i = 1; i <= n; i++) {
        int _v;
        cin >> _v;

        values.push_back(_v);
    }

    vector<int> traces;

    solve(n, W, weights, values);
    return 0;
}