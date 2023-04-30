#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int units[3] = {0, 0, 0};
    int nCount = 0;
    int index = 2;
    while(n != 0){
        nCount++;
        units[index] = n % 10;
        n /= 10;
        index--;
    }

    char *speech[10] = {"", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};

    int isHundered = units[0] != 0, isTen = units[1] != 0, isUnit = units[2] != 0;
    if(!isHundered && !isTen && !isUnit){
        printf("khong");
    }else if(!isHundered && units[1] == 1 && !isUnit){
        printf("muoi");
    }
    else{
        if(isHundered){
            printf("%s tram ", speech[units[0]]);
        }

        if(!isHundered && !isTen){
        }else if(!isTen && isUnit){
            printf("linh ");
        }else if(isTen){
            printf("%s muoi ", speech[units[1]]);
        }

        speech[5] = "lam";
        if(isUnit){
            printf("%s", speech[units[2]]);
        }
    }
}