#include <stdio.h>

int main () {
    int d, M, y;
    scanf("%d %d %d", &d, &M, &y);

    y = y % 100;
    printf("%.2d/%.2d/%.2d", d, M, y);
}