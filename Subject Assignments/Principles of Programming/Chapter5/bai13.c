#include <stdio.h>

int main() {
    int oldKW, newKW;
    scanf("%d %d", &oldKW, &newKW);
    int kw = newKW - oldKW;
    int tong = 0;

    int count = 0;
    int price[3] = {1500, 2300, 3500};
    while(count <= 2 && kw > 0) {
        int calculating = (kw >= 50 && count != 2) ? 50 : kw;
        kw -= calculating;
        tong += price[count] * calculating;
        count++;
        if(count > 2)
            break;
    }

    printf("%d", tong);
}