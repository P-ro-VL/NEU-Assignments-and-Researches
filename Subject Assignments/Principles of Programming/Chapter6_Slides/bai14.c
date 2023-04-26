#include <stdio.h>
#include <string.h>

int table[50][50];

int max(int a, int b){
    return a >= b ? a : b;
}

int min(int a, int b){
    return a >= b ? b : a;
}

void explode(int x, int y, int m, int n){
    int toExplode[4][2] = {
        {min(m - 1, x + 1), y},
        {max(0, x - 1), y},
        {x, min(n - 1, y + 1)},
        {x, max(0, y - 1)}
    };

    for (int i = 0; i < 4; i++){
        int posX = toExplode[i][0], posY = toExplode[i][1];
        if(posX == x && posY == y)
            continue;
        if(table[posX][posY] == 99){
            table[posX][posY] = 1;
            explode(posX, posY, m, n);
        }else{
            table[posX][posY] = 1;
        }
    }
}

void solve(int explodeX, int explodeY, int m, int n) {
    explode(explodeX, explodeY, m, n);
}

int main()
{
    for (int i = 0; i < 50; i++)
        memset(table[i], 0, 50);

    int m, n;
    scanf("%d %d", &m, &n);

    int k;
    scanf("%d", &k);

    while(k--){
        int x, y;
        scanf("%d %d", &x, &y);
        table[x][y] = 99;
    }

    int explodeX, explodeY;
    scanf("%d %d", &explodeX, &explodeY);

    solve(explodeX, explodeY, m, n);

    int count = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if(table[i][j] == 1)
                count++;

    printf("%d", count);
}