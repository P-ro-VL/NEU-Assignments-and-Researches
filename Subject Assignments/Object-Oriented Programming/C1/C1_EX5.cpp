#include <iostream.h>
#include <conio.h>
#include <iomanip.h>

/* Khai báo các nguyên mẫu hàm */
void nhapds(int *x, int n);
void nhapds(double *x, int n);
int max(int x,int y);
double max(double x, double y);

/* Yêu cầu người dùng nhập n phần tử nguyên vào mảng x */
void nhapds(int *x, int n)
{
    for(int i=0;i<n;++i) {
        cout<<"Phan tu "<<i<<" = "; cin>>x[i];
    }
}

/* Yêu cầu người dùng nhập n phần tử thực vào mảng x */

void nhapds(double *x, int n) {
    for (int i=0;i<n;i++)
    {
    cout<<"Phan tu "<<i<<" = "; cin>>x[i];
    }
}

/* Trả về số lớn hơn trong 2 số nguyên x, y */
int max(int x, int y) {
    return x > y ? x : y;
}

/* Trả về số lớn hơn trong 2 số thực x, y */
double max(double x, double y)
{
    return x > y ? x : y;
}

/* Trả về số nguyên lớn nhất trong mảng x gồm n phần tử */
int max(int *x, int n) {
    int s=x[0];
    for(int i=1;i<n;++i) s = max(s,x[i]); // so sánh số s hiện tại với giá trị x[i]
                                          // nếu x[i] > s thì s mới sẽ bằng x[i]
    return s;
}

/* Trả về số thực lớn nhất trong mảng x gồm n phần tử */
double max(double *x, int n) {
    double s=x[0];
    for(int i=1;i<n;++i) s = max(s,x[i]);
    return s;
} 

main() {
    int a[20], n, ni, nd, maxi;
    double x[20], maxd;

    /* Nhập vào số phần tử nguyên, số phần tử thực và các giá trị nguyên, thực tương ứng */
    cout<<"\n So phan tu nguyen n: "; cin>>ni;
    cout<<"\n Nhap day so nguyen: "; nhapds(a,ni);
    cout<<"\n So phan tu so thuc: "; cin>>nd;
    cout<<"\n Nhap day so thuc: "; nhapds(x,nd);

    /* Tính toán tìm ra giá trị lớn nhất trong hai mảng */
    maxi = max(a,ni);
    maxd = max(x,nd);

    /* In kết quả ra màn hình */
    cout<<"\n Max day so nguyen ="<<maxi;
    cout<<"\n Max day so thuc="<<maxd;

    /* Đợi người dùng nhấn nút bất kỳ để kết thúc chương trình */
    getch();
}
