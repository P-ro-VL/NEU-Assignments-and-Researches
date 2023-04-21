#include <stdio.h>

int main() {
    int n = 0;
    while(n < 10 || n > 100){
        scanf("%d", &n);
    }
    for (int i = 2; i <= n; i++){
        if(n % i == 0)
            printf("%d ", i);
    }
}