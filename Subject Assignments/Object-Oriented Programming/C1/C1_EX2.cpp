#include <stdio.h>
#include <conio.h>
main() {
    /* In ra thông báo và nhập vào số phần tử của dãy */
    int n;
    printf("\n So phan tu cua day n="); scanf("%d",&n);

    /* Khởi tạo biến tổng ban đầu mang giá trị 0.0 */
    float s = 0.0;

    /* Chạy i từ 1 đến n và tính cộng thêm một lượng (1/i) vào s */
    for (int i=1;i<=n;++i)
        s+= 1/i;

    /* In ra kết quả */
    printf("S=%0.2f",s);

    /* Đợi người dùng nhấn nút bất kỳ để kết thúc chương trình */
    getch();
}