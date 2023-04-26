#include <stdio.h>

int main() {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d,m,y,n;
    scanf("%d/%d/%d %d", &d, &m, &y, &n);

    int pd = d, pm = m, py = y;

    while(n--){
        if(y % 4 == 0) daysInMonth[1] = 29;
        pd -= 1;
        if(pd <= 0){
            if(pm - 1 == 0){
                pm = 13;
                py--;
            }
            pm--;
            pd = daysInMonth[pm - 1];
        }
    }

    printf("%.2d/%.2d/%d", pd, pm, py);
}