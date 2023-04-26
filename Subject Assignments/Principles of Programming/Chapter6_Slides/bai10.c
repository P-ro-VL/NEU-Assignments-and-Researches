#include <stdio.h>

int isValidDate(int d, int m, int y){
    return (d >= 1 && d <= 31) && (m >= 1 && m <= 12) && y > 0;
}

int compareDate(int d1, int m1, int y1, int d2, int m2, int y2){
    if(y2 < y1)
        return 0;
    if(y2 == y1 && m2 < m1)
        return 0;
    if(y2 == y1 && m2 == m1 && d2 < d1)
        return 0;
    return 1;
}

int main() {
    int dd1, MM1, yy1, dd2, MM2, yy2;
    scanf("%d/%d/%d", &dd1, &MM1, &yy1);
    scanf("%d/%d/%d", &dd2, &MM2, &yy2);

    if(!isValidDate(dd1, MM1, yy1) || !isValidDate(dd2, MM2, yy2) 
    || !compareDate(dd1, MM1, yy1, dd2, MM2, yy2)){
      printf("Ngay thang khong hop le");
     }else{
        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int d = dd1, m = MM1, y = yy1;

        int count = 0;
        while(d != dd2 || m != MM2 || y != yy2){
            int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if(y % 4 == 0) daysInMonth[1] = 29;

            d = d + 1, m = m, y = y;
            int maxDay = daysInMonth[m - 1];
            if(d > maxDay){
                d = 1;
                m = m + 1;
            }

            if(m > 12){
                m = 1;
                y = y + 1;
            }

            count++;
        }

        printf("%d", count);
    }
}