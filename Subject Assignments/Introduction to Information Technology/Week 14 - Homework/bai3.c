#include <stdio.h>

int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(n>= 1 && n <= 12){
            if(n >=1 && n <= 3) printf("Quy 1");
            else if(n >= 4 && n<=6) printf("Quy 2");
            else if(n>=7 && n<=10) printf("Quy 3");
            else printf("Quy 4");
            break;
        }
    }
    return 0;
}