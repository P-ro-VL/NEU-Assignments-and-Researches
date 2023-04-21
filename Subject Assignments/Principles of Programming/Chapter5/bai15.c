#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if(n == 1 || n == 2){
        printf("1");
    }else{
        int count = 3;
        int a = 1, b = 1, temp;
        for (int i = 3; i <= n; i++){
            temp = b;
            b = a + b;
            a = temp;
        }

        printf("%d", b);
    }


}