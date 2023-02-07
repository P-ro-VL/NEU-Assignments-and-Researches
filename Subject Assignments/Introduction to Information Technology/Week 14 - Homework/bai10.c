#include <stdio.h>  

int main() {

    char *numberSpeech[9] = {"một", "hai", "ba", "bốn", "năm", "sáu", "bảy", "tám", "chín"};

    while(1){
        int n;
        scanf("%d", &n);
        if(n >= 10 && n <= 99){
            if(n == 10){
                printf("Mười");
                break;
            }

            int hangDonVi = n%10, hangChuc = n/10;
            if(hangChuc == 1){
                printf("Mười %s", numberSpeech[hangDonVi - 1]);
            }else {
                printf("%s mươi %s", numberSpeech[hangChuc - 1], numberSpeech[hangDonVi - 1]);
            }
            break;
        }
    }
}