#include <bits/stdc++.h>

using namespace std;

void toHop(vector<vector<int>> &ans, vector<int> &temp, int n, int k, int left) {
    if(k == 0) {
        ans.push_back(temp);
        return;
    }

    for (int i = left; i <= n; i++) {
        temp.push_back(i);
        toHop(ans, temp, n, k - 1, i + 1);

        temp.pop_back();
    }
}

vector<vector<int>> solve(int n, int k) {
    vector<vector<int>> ans;
    vector<int> temp;

    toHop(ans, temp, n, k, 1);
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> solution = solve(n, k);

    cout << solution.size() << endl;

    for(auto c : solution) {
        for(auto num : c) {
            cout << num << " ";
        }
        cout << endl;
    }

}