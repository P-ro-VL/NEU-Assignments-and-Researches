#include <stdio.h>
#include <string.h>

int main() {

    int length = 0;
    char c[100001];
    memset(c, 0, 100001);

    int count[91];
    memset(count, 0, 91);

    gets(c);

    for (int i = 0; i < 100001; i++) {
        count[c[i]]++;
    }

    int oddCount = 0;
    for (int i = 65; i < 91; i++) {
        if(count[i] % 2 != 0) {
            oddCount++;
        }
    }

    if(oddCount == 0 || oddCount == 1) {
        printf("0");
    } else {
        printf("%d", oddCount / 2);
    }
}