#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    cin.ignore();
    getline(cin, s);

    while(s[0] == ' '){
        s = s.substr(1, s.length());
    }    

    while(s[s.length() - 1] == ' '){
        s = s.substr(0, s.length() - 1);
    }

    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ' && s[i + 1] == ' '){
            s.erase(i, 1);
            i--;
        }         
    }

    cout<<s;
}