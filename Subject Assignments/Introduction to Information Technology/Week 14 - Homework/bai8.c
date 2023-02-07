#include <stdio.h>

int main(){
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d,m,y;
    scanf("%d %d %d", &d, &m, &y);

    if(y % 4 == 0) daysInMonth[1] = 29;

    int pd = d - 1, pm = m, py = y;
    if(pd <= 0){
        if(m - 1 == 0){
            pm = 12;
            py--;
        }
        pm--;
        pd = daysInMonth[pm - 1];
    }

    printf("Ngay hom truoc la %d/%d/%d", pd, pm, py);
}