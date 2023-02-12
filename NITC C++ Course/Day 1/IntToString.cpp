#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;

    int n;
    cin>>n;

    int index = 0;
    while(n != 0){
        int charNum = n % 10;
        s = ((char) ('0' + charNum)) + s;
        n /= 10;
        index++;
    }

    cout<<s;

    return 0;
}