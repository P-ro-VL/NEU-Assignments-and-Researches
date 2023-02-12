#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin>>s;

  int character[200] = {};
  memset(character, 0, sizeof(character));
  for(int i = 0; i < s.length(); i++){
    char kitu = s[i];
    character[kitu]++;
  }

  int count = 0;
  for(int i = 48; i <= 122; i++){
    if(character[i] > 0) count++;
  }

  cout<<count;
  return 0;
}