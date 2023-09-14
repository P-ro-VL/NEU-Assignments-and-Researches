#include <stdio.h>

int main() {
    int n, m;
    int ban[n][m];
    int gia[m];

    int tongDoanhThuCongty = 0;
    int doanhThu[n];
    for (int cuaHang = 0; cuaHang < n; cuaHang++) {
        int doanhThuCuaHang = 0;
        for (int matHang = 0; matHang < m; matHang++) {
            doanhThuCuaHang = doanhThuCuaHang + ban[cuaHang][matHang] * gia[matHang];
        }
        doanhThu[cuaHang] = doanhThuCuaHang;
        tongDoanhThuCongty = tongDoanhThuCongty + doanhThuCuaHang;
    }

    int doanhThuTrungBinh = tongDoanhThuCongty / n;
    for (int cuaHang = 0; cuaHang < n; cuaHang++) {
        if(doanhThu[cuaHang] > doanhThuTrungBinh) {
            printf("Cua hang %d", cuaHang);
        }
    }
}