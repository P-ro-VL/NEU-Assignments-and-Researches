#include <iostream> // thu vien cout, cin
#include <conio.h> // thu vien getch()
#include <iomanip> // thu vien setw
#include <string.h> // thu vien ham chuoi ky tu
#include <bits/stdc++.h>

using namespace std;

main() {
    /* Khởi tạo một cấu trúc lưu trữ dữ liệu các thí sinh */
    struct {
        char ht[25]; // Họ tên thí sinh
        float d1, d2, d3, td; // Điểm các môn 1 2 3 và tổng điểm (td)
    } ts[100], tg; // Mảng thí sinh có sức chứa 100 phần tử, và biến tg trung gian

    /* Nhập vào số lượng thí sinh */
    int n, i, j;
    cout << "So thi sinh: "; cin>>n; cin.ignore(1);

    /* Nhập vào thông tin của từng thí sinh, bao gồm họ tên và điểm các môn thi */
    /* sau đó tính tổng điểm td */
    for (i=0; i<n; ++i) {
        cout << "\n Thi sinh: "<<i;
        cout << "\n Ho ten:";
        cin.get(ts[i].ht,25); cin.ignore(1); // Nhập vào họ tên
        cout << "\nDiem cac mon thi :";
        cin >> ts[i].d1>>ts[i].d2>>ts[i].d3; // Nhập điểm các môn 1 2 3
        cin.ignore(1); 
        ts[i].td=ts[i].d1+ts[i].d2+ts[i].d3; // Tính tổng điểm
    }
    
    /* Sắp xếp lại mảng thí sinh dựa trên tổng điểm bằng phương pháp sắp xếp nổi bọt */
    for (i=0;i<n-1;++i)
        for(j=i+1;j<n;++j)
            if(ts[i].td<ts[j].td) {
                tg=ts[i]; ts[i]=ts[j]; ts[j]=tg;
            }

    /* In ra danh sách thí sinh kèm tổng điểm sau khi đã sắp xếp */
    cout<< "\ Danh sach thi sinh sau khi sap xep :";
    for (i=0;i<n;++i) {
        cout<<"\n"<<
        setw(25)<<ts[i].ht<<setw(5)<<ts[i].td; // Hàm setw(int): để dành x khoảng trống để in dữ liệu ra.
    }

    /* Đợi người dùng nhấn nút bất kỳ để kết thúc chương trình */
    getch();

}