#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    int m = x, n = y;
    while(m != n){
        if(m > n)
            m = m - n;
        else if(m < n)
            n = n - m;
    }

    int BCNN = (x * y) / m;

    printf("UCLN: %d\nBCNN: %d", m, BCNN);
}