#include <stdio.h>
#include <math.h>

int main(){
    int isPrime = 0;
    while(1) {
        int n;
        scanf("%d", &n);
        if(n >= 2 && n <= 1000){
            if(n < 2) break;
            if(n == 2) {
                isPrime = 1;
                break;
            }
            if(n % 2 == 0) break;

            int found = 0;
            for(int i = 3; i < sqrt(n); i += 2){
                if(n % i == 0) {
                    found = 1;
                    break;
                }
            }

            if(found == 0){
                isPrime = 1;
            }
            break;
        }
    }

    if(isPrime){
        printf("La so nguyen to");
    }else{
        printf("Khong phai so nguyen to");
    }

    return 0;
}