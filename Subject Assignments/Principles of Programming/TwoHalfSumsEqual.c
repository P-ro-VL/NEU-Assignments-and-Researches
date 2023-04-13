#include <stdio.h>
#include <math.h>

int main() {
    int number;
    scanf("%d", &number);

    int soChuSo = floor(log10(number)) + 1;
    if(soChuSo % 2 != 0){
        printf("Khong may man");
    }else{
        int middle = soChuSo / 2;
        int firstSum = 0;
        int secondSum = 0;

        int index = soChuSo - 1;
        while(index >= 0) {
            int value = number % 10;
            if(index >= middle) {
                secondSum += value;
            } else {
                firstSum += value;
            }
            number /= 10;
            index--;
        }

        printf(firstSum == secondSum ? "May man" : "Khong may man");
    }
}