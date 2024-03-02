#include <bits/stdc++.h>

using namespace std;

class Nguoi
{
private:
    string maSo;
    string hoTen;
    double luong;

public:
    void nhap()
    {
        cout << "Nhap ma so: ";
        cin.ignore(1);
        cin >> maSo;
        cout << "Nhap ho ten: ";
        cin.ignore(1);
        cin >> hoTen;
        cout << "Nhap luong: ";
        cin >> luong;
    }
};

class Bienche : virtual public Nguoi
{
private:
    double heSoLuong;
    double tienPhuCapCV;

public:
    void nhap_bc()
    {
        cout << "Nhap he so luong: ";
        cin >> heSoLuong;
        cout << "Nhap tien phu cap cong viec: ";
        cin >> tienPhuCapCV;
    }
};

class Hopdong : virtual public Nguoi
{
private:
    double tienCong;
    int soNgayLamViec;
    double heSoVuotGio;

public:
    void nhap_hd()
    {
        cout << "Nhap tien cong: ";
        cin >> tienCong;
        cout << "So ngay lam viec: ";
        cin >> soNgayLamViec;
        cout << "Nhap he so vuot gio: ";
        cin >> heSoVuotGio;
    }
}

class Vienchuc : public Bienche,
                 public Hopdong
{
public:
    void nhapVC()
    {
    }
}

int
main()
{
    int n;
    cout << "Nhap so vien chuc: ";
    cin >> n;

    Vienchuc vc[n];
    for (int i = 0; i < n; i++)
    {
        vc[i].nhapVC();
    }

    cout << "Danh sach vua nhap: ";
    for (int i = 0; i < n; i++)
    {
        vc[i].in();
    }

    return 0;
}