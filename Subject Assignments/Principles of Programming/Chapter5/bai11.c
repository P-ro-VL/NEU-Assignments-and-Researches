#include <stdio.h>

int main(){
    int t, l, h;
    scanf("%d %d %d", &t, &l, &h);

    int tong = t + l + h;
    printf(tong >= 15 ? "DAT\n" : "KHONG DAT\n");
    if(tong >= 15)
        printf((t >= 7 && l >= 7 && h >= 7) ? "Hoc deu cac mon" : "Hoc chua deu cac mon");
}