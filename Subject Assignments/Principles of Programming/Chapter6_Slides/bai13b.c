#include <stdio.h>
#include <string.h>

int SIEVE[10000];
int m, n;

void swap(int *number, int l, int r){
    int temp = number[l];
    number[l] = number[r];
    number[r] = temp;
}

int permute(int number[4], int l, int r){
    if(l == r){
        int value = number[0] * 1000 + number[1] * 100 + number[2] * 10 + number[3];
        if(value < m || value > n)
            return 0;
        SIEVE[value] = 1;
        return 1;
    }else{
        for (int i = l; i <= r; i++) {
            swap(number, l, i);
            permute(number, l + 1, r);
            swap(number, l, i);
        }
    }
}

void preInit(int m, int n) {
    for (int i = m; i <= n; i++){
        int units[4];
        int count = 0;
        int n = i;
        while(n>0){
            units[count] = n % 10;
            n /= 10;
            count++;
        }

        int result = permute(units, 1, count - 1);
    }
}

int tongTriet(int n){
    int k = n;
    while(k >= 10){
        int sum = 0;
        int h = k;
        while(h > 0){
            sum += h % 10;
            h /= 10;
        }
        k = sum;
    }
    return k;
}

int main() {
    int k;
    scanf("%d %d", &m, &n);
    scanf("%d", &k);

    memset(SIEVE, 1, 10000);
    preInit(m, n);

    int count = 0;
    for (int i = m; i <= n; i++)
        if(tongTriet(i) == k && SIEVE[i]){
            printf("%d\n", i);
            count++;
        }
    printf("%d", count);
}