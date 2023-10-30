#include <iostream>
#include <stdlib>
#include <conio.h>

using namespace std;

class sinhvien
{
    char hoten[25];

protected:
    int sbd;

public:
    void nhap()
    {
        cout << endl
             << "Ho ten :";
        gets(hoten);
        cout << endl
             << "So bao danh :";
        cin >> sbd;
        cin.ignore(1);
    }

    void hienthi()
    {
        cout << endl
             << "So bao danh: " << sbd;
        cout << endl
             << "Ho va ten sinh vien: " << hoten;
    }
};

class diemthi : public sinhvien
{
protected:
    float d1, d2;

public:
    void nhap_diem()
    {
        cout << "Nhap diem hai mon thi : \n";
        cin >> d1 >> d2;
    }

    void hienthi_diem()
    {
        cout << "Diem mon 1 :" << d1 << endl;
        cout << "Diem mon 2 :" << d2 << endl;
    }
};

class ketqua : public diemthi
{
    float tong;

public:
    void display()
    {
        tong = d1 + d2;
        hienthi();
        hienthi_diem();
        cout << "Tong so diem :" << tong << endl;
    }
};

int main()
{
    int i, n;
    ketqua sv[100];

    cout << "\n Nhap so sinh vien : ";
    cin >> n;
    cin.ignore(1);

    for (i = 0; i < n; ++i)
    {
        sv[i].nhap();
        sv[i].nhap_diem();
    }

    for (i = 0; i < n; ++i)
        sv[i].display();

    getch();
    return 0;
}