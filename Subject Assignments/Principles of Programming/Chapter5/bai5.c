#include <stdio.h>
#include <math.h>

int main() {

    int n;
    while(n < 2 || n > 1000){
        scanf("%d", &n);
    }

    if(n == 2){
        printf("La so nguyen to");
    }else if(n%2==0){
        printf("Khong la so nguyen to");
    }else{
        int found = 0;
        for (int i = 3; i < sqrt(n); i+=2)
            if(n%i==0){
                printf("Khong la so nguyen to");
                return 0;
            }
        printf("La so nguyen to");
    }
}