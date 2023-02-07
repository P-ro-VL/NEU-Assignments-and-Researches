#include <stdio.h>

int main(){
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d,m,y;
    scanf("%d %d %d", &d, &m, &y);

    if(y % 4 == 0) daysInMonth[1] = 29;

    int nd = d + 1, nm = m, ny = y;
    int maxDay = daysInMonth[m - 1];
    if(nd > maxDay){
        nd = 1;
        nm = m + 1;
    }

    if(nm > 12){
        nm = 1;
        ny = y + 1;
    }

    printf("Ngay tiep theo la %d/%d/%d", nd, nm, ny);
}