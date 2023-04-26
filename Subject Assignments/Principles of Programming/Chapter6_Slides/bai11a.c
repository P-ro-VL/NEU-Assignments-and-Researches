#include <stdio.h>

int main() {
    int d, m, y, n;
    scanf("%d/%d/%d %d", &d, &m, &y, &n);

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int nd = d, nm = m, ny = y;
    while (n--)
    {
        if(ny % 4 == 0) daysInMonth[1] = 29;

        nd += 1;
        int maxDay = daysInMonth[nm - 1];
        if(nd > maxDay){
            nd = 1;
            nm = nm + 1;
        }

        if(nm > 12){
            nm = 1;
            ny = ny + 1;
        }
    }

    printf("%.2d/%.2d/%d", nd, nm, ny);
}