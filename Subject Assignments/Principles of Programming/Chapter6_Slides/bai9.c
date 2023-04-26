#include <stdio.h>

int isValidDate(int d, int m, int y){
    return (d >= 1 && d <= 31) && (m >= 1 && m <= 12) && y > 0;
}

int main() {
    int d, m, y;
    scanf("%d/%d/%d", &d, &m, &y);

    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(!isValidDate(d, m, y)){
        printf("Khong phai ngay thang");
    }else{
        if(y % 4 == 0)
            months[1] = 29;

        if(d > months[m-1])
        {
            printf("Ngay thang khong hop le");
        }else{
            printf("Ngay thang hop le");
        }
    }
}