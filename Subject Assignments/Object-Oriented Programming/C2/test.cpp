#include <iostream>
#include <math.h>
using namespace std;
class PHANSO
{
private:
    int tu, mau;

public:
    PHANSO()
    {
        tu = 0;
        mau = 1;
    }
    PHANSO(int t, int m)
    {
        tu = t;
        mau = m;
    }
    void nhap()
    {
        cout << endl
             << "Tu so: ";
        cin >> tu;
        cout << endl
             << "Mau so: ";
        cin >> mau;
    }
    void in()
    {
        cout << endl
             << tu << "/" << mau;
    }
    int ucln()
    {
        int t = abs(tu), m = abs(mau);
        while (t * m != 0)
        {
            if (t > m)
                t = t % m;
            else
                m = m % t;
        }
        return (t + m);
    }
    PHANSO *toigian()
    {
        int c = ucln();
        tu = tu / c;
        mau = mau / c;
        return this;
    }
    PHANSO cong(PHANSO f)
    {
        PHANSO tg;
        tg.tu = (this->tu * f.mau) + (f.tu * this->mau);
        tg.mau = this->mau * f.mau;
        tg.toigian();
        return (tg);
    }
    // Tuong duong voi
    PHANSO operator+(PHANSO p2)
    {
        PHANSO tg;
        tg.tu = tu * p2.mau + mau * p2.tu;
        tg.mau = mau * p2.mau;
        tg.toigian();
        return (tg);
    }

    PHANSO tru(PHANSO f)
    {
        PHANSO tg;
        tg.tu = (this->tu * f.mau) - (f.tu * this->mau);
        tg.mau = this->mau * f.mau;
        tg.toigian();
        return tg;
    }
    PHANSO nhan(PHANSO f)
    {
        PHANSO tg;
        tg.tu = this->tu * f.tu;
        tg.mau = this->mau * f.mau;
        tg.toigian();
        return tg;
    }
    // Tuong duong
    PHANSO operator*(PHANSO f)
    {
        PHANSO tg;
        tg.tu = this->tu * f.tu;
        tg.mau = this->mau * f.mau;
        tg.toigian();
        return tg;
    }
    PHANSO chia(PHANSO f)
    {
        PHANSO tg;
        tg.tu = this->tu * f.mau;
        tg.mau = this->mau * f.tu;
        tg.toigian();
        return tg;
    }
    bool SOSANH(PHANSO f)
    {
        return (float((this->tu) / (this->mau)) < (float((f.tu) / (f.mau))));
    }
    void reset(int t, int m)
    {
        tu = t;
        mau = m;
    }
    PHANSO operator-()
    {
        PHANSO tg;
        tg.tu = -tg.tu;
        return tg;
    }
    friend bool operator<(PHANSO p1, PHANSO p2);
    friend bool operator<=(PHANSO p1, PHANSO p2);
    friend bool operator==(PHANSO p1, PHANSO p2);
    friend bool operator>=(PHANSO p1, PHANSO p2);
    friend bool operator>(PHANSO p1, PHANSO p2);
    friend bool sosanh(PHANSO p1, PHANSO p2);
};

bool operator<(PHANSO p1, PHANSO p2)
{
    return (float(p1.tu) / p1.mau < float(p2.tu) / p2.mau);
}
bool operator<=(PHANSO p1, PHANSO p2)
{
    return (float(p1.tu) / p1.mau <= float(p2.tu) / p2.mau);
}
bool operator==(PHANSO p1, PHANSO p2)
{
    return (float(p1.tu) / p1.mau == float(p2.tu) / p2.mau);
}
bool operator>=(PHANSO p1, PHANSO p2)
{
    return (float(p1.tu) / p1.mau >= float(p2.tu) / p2.mau);
}
bool operator>(PHANSO p1, PHANSO p2)
{
    return (float(p1.tu) / p1.mau > float(p2.tu) / p2.mau);
}
bool sosanh(PHANSO p1, PHANSO p2)
{
    return (float(p1.tu) / p1.mau < float(p2.tu) / p2.mau);
}

int main()
{
    cout << "Nhap vao so cac phan so: ";
    int n;
    cin >> n;
    PHANSO *p = new PHANSO[n];
    cout << endl
         << "Nhap vao phan so: ";
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "Phan so thu " << i + 1;
        p[i].nhap();
    }
    cout << endl
         << "Cac phan so da nhap: ";
    for (int i = 0; i < n; i++)
    {
        p[i].in();
    }
    cout << endl
         << "Phan so da toi gian la: ";
    for (int i = 0; i < n; i++)
    {
        p[i].toigian();
        p[i].in();
    }
    cout << endl
         << "Tong cac phan so la: ";
    PHANSO sum = p[0];
    for (int i = 1; i < n; i++)
    {
        sum = sum + p[i];
        // tuong duong sum=sum.cong(p[i]);
    }
    sum.toigian();
    sum.in();
    cout << endl
         << "Hieu cac phan so: ";
    PHANSO sub = p[0];
    for (int i = 1; i < n; i++)
    {
        sub = sub.tru(p[i]);
    }
    sub.toigian();
    sub.in();
    cout << endl
         << "Tich cac phan so: ";
    PHANSO mul = p[0];
    for (int i = 1; i < n; i++)
    {
        mul = mul * p[i];
    }
    mul.toigian();
    mul.in();
    cout << endl
         << "Thuong cac phan so: ";
    PHANSO dev = p[0];
    for (int i = 1; i < n; i++)
    {
        dev = dev.chia(p[i]);
    }
    dev.toigian();
    dev.in();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].SOSANH(p[j]))
            {
                PHANSO tg = p[i];
                p[i] = p[j];
                p[j] = tg;
            }
        }
    }
}