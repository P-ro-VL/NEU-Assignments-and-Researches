#include <bits/stdc++.h>
#include <conio.h>

main() {
    int n;
    /* In ra thông báo và yêu cầu nhập vào số phần tử của dãy cần sắp xếp*/
    printf("\n So phan tu cua day n="); scanf("%d",&n);
    
    /* Tạo một mảng x chứa các phần tử bằng cách cấp phát động thông qua hàm malloc() */
    float *x=(float*) malloc((n+1)*sizeof(float));
    
    /* Vòng lặp để nhập vào các giá trị của mảng x */
    for (int i=0;i<n;i++) {
        printf("\n X[%d]=",i); scanf("%f",x+i);//&x[i]
    }

    int i;
    float tg;

    /* Sắp xếp mảng x bằng thuật toán sắp xếp nổi bọt */
    for(i=0;i<n-1;++i)
        for (int j=i+1;j<n;++j)
            if (x[i]>x[j]) {
                tg = x[i]; x[i] = x[j]; x[j] = tg;
            }

    /* In ra mảng x sau khi đã sắp xếp */
    printf("\n Day sau khi sap xep\n");

    for (i=0;i<n;++i)
        printf("%0.2f ",x[i]);//*(x+i)
    
    /* Giải phóng bộ nhớ của mảng x */
    free(x);

    /* Đợi người dùng nhấn nút bất kỳ để kết thúc chương trình */
    getch();
}