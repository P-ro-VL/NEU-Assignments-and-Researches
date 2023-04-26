/*
https://2.bp.blogspot.com/-QpOzziwDirQ/VlwUp0X1YUI/AAAAAAAAIZc/Nv6KjoxoQR0/s1600/dien-tich-tam-giac-theo-toa-do-dinh.jpg
*/

#include <stdio.h>
#include <stdlib.h>

float area(float xa, float ya, float xb, float yb, float xc, float yc){
    return 0.5 * abs((xb - xa) * (yc - ya) - (xc - xa) * (yb - ya));
}

int isInside(float xa, float ya, float xb, float yb, float xc, float yc, float xm, float ym) {
    float originArea = area(xa, ya, xb, yb, xc, yc);

    float area1 = area(xa, ya, xb, yb, xm, ym);
    float area2 = area(xb, yb, xc, yc, xm, ym);
    float area3 = area(xa, ya, xc, yc, xm, ym);

    if(area1 == 0 || area2 == 0 || area3 == 0)
        return -1;

    return (originArea) == (area1 + area2 + area3);
}

int main() {
    float xa, ya, xb, yb, xc, yc, xm, ym;
    //printf("Nhap toa do diem A:");
    scanf("%f %f", &xa, &ya);
    //printf("Nhap toa do diem B:");
    scanf("%f %f", &xb, &yb);
    //printf("Nhap toa do diem C:");
    scanf("%f %f", &xc, &yc);
    //printf("Nhap toa do diem M:");
    scanf("%f %f", &xm, &ym);

    int value = isInside(xa, ya, xb, yb, xc, yc, xm, ym);
    if(value == -1){
        printf("NAM TREN");
    } else
        if(value)
            printf("NAM TRONG");
        else
            printf("NAM NGOAI");
}