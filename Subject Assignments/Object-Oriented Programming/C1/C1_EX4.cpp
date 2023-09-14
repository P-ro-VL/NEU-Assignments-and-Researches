#include <iomanip.h>
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Khởi tạo một biến cấu trúc lưu trữ thông tin của các thí sinh 
bao gồm họ tên, số báo danh và tổng điểm */
struct TS {
    char ht[20];
    long sobd;
    float td;
};

main()
{
    TS *ts;
    /* Nhập vào số thí sinh n */
    int n;
    cout<<"\nSo thi sinh n = "; cin>>n;

    /* Khởi tạo mảng chứa thông tin các thí sinh */
    ts = new TS[n+1]; // sử dụng toán tử new để khởi tạo

    /* Kiểm tra xem đã cấp phát vùng nhớ cho biến con trỏ ts thành công chưa,
    nếu chưa thì in thông báo lỗi và kết thúc chương trình */
    if (ts == NULL) {
        cout << "\n Loi cap phat vung nho";
        getch();
        exit(0);
    }

    /* Nhập thông tin cho các thí sinh */
    for (int i=0;i<n;++i) {
        cout << "\n Thi sinh thu "<<i+1;
        cout<< "\n Ho ten";
        cin.ignore(1);
        cin.get (ts[i].ht,20); // Nhập họ tên
        cout << "so bao danh";
        cin>> ts[i].sobd; // Nhập SBD
        cout<< "tong diem:";
        cin>>ts[i].td; // Nhập tổng điểm
    }

    /* Sắp xếp lại danh sách thí sinh theo tổng điểm bằng phương pháp sắp xếp nổi bọt */
    for (i=0;i<n-1;++i)
        for (int j=i+1;j<n;++j)
            if (ts[i].td<ts[j].td) {
                TS tg=ts[i]; ts[i]=ts[j]; ts[j]=tg;
            }

    /* In ra kết quả sau khi đã sắp xếp */
    for (i=0;i<n;++i)
        cout << "\n" << setw(20)<<ts[i].ht<<setw(6)<<ts[i].td;

    /* Giải phóng bộ nhớ */
    delete ts;

    /* Đợi người dùng nhấn nút bất kỳ để kết thúc chương trình */
    getch();
}