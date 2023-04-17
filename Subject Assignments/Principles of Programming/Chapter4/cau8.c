#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    int H, m;
    H = t / (60*60);
    t -= H * 60 * 60;
    m = t / 60;
    t -= m * 60;
    printf("%.2d:%.2d:%.2d", H, m, t);
}
