#include <stdio.h>
#include <string.h>

int SIEVE[10000];
int duyet[10000];
int recent[24], INDEX = 0;
int m, n, k, count = 0;

void swap(int *number, int l, int r){
    int temp = number[l];
    number[l] = number[r];
    number[r] = temp;
}

void permute(int number[4], int l, int r){
    if(l == r){
        int value = number[3] * 1000 + number[2] * 100
         + number[1] * 10 + number[0];
        SIEVE[value] = 1;
        duyet[value] = 1;
    }else{
        for (int i = l; i <= r; i++) {
            swap(number, l, i);
            permute(number, l + 1, r);
            swap(number, l, i);
        }
    }
}

int tongTriet(int n){
    int k = n;
    while(k >= 10){
        int sum = 0;
        int h = k;
        while(h > 0){
            sum += (h % 10);
            h /= 10;
        }
        k = sum;
    }
    return k;
}

void preInit(int m, int n)
{
    if(m > n)
        return;
    if(duyet[m] == 1) {
        preInit(m + 1, n);
        return;
    }

    int units[4];
    int count = 0;
    int h = m;
    while (h > 0)
    {
        units[count] = h % 10;
        h /= 10;
        count++;
    }

    permute(units, 0, count - 1);
    SIEVE[m] = 0;
    preInit(m + 1, n);
}


int main() {
    scanf("%d %d", &m, &n);
    scanf("%d", &k);

    memset(SIEVE, 1, 10000);
    memset(duyet, 0, 10000);

    preInit(m, n);

    for (int i = m; i <= n; i++){
        if(tongTriet(i) == k && SIEVE[i]){
            printf("%d\n", i);
            count++;
        }
    }

    printf("%d", count);
}