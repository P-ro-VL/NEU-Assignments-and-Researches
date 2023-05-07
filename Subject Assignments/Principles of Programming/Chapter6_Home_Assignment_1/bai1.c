#include <stdio.h>

int isPerfectNumber(int n) {
    int tong = 0;
    for(int i = 1; i < n; i++){
        if(n % i == 0){
        tong += i;
        }
    }
    return tong == n;
}

int main() {
    int n;
    scanf("%d", &n);
    printf(isPerfectNumber(n) ? "N la so hoan chinh" : "N khong la so hoan chinh");

    printf("\n");
    for (int i = 0; i <= 1000; i++)
        if(isPerfectNumber(i))
        printf("%d ", i);
}