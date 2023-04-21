#include <stdio.h>

int main() {
    int n = 0;
    while(n < 1 || n > 12){
        scanf("%d", &n);
    }

    switch (n)
    {
    case 1:
    case 2:
    case 3:
        printf("Quy 1");
        break;
    case 4:
    case 5:
    case 6:
        printf("Quy 2");
        break;
    case 7:
    case 8:
    case 9:
        printf("Quy 3");
        break;
    default:
        printf("Quy 4");
        break;
    }
}