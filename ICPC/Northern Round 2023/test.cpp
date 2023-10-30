#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    char map[N][M];
    int countEnemy[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++)
        {
            char ch;
            cin >> ch;
            map[i][j] = ch;
            if(ch == 'x') {
                countEnemy[i][j]++;
            }
        }
    }

    while(1) {
        int min = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {

            }
        }
    }
}