#include <stdio.h>

int main() {
    int maSV, toan, li, hoa;
    printf("Nhap ma SV: ");
    scanf("%d", &maSV);
    printf("Nhap diem Toan Li Hoa: ");
    scanf("%d %d %d", &toan, &li, &hoa);

    printf("Diem trung binh cua sinh vien %d la %.2f", maSV, (toan + li + hoa) / 3.0);
}