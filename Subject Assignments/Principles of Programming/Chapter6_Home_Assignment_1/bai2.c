#include <stdio.h>
#include <string.h>

int primeSieve[1001];

int sieveInit();
int isPrimeNumber(int n);
void printPrimeNumberInRange(int startIndex, int endIndex);

int main() {
    memset(primeSieve, 0, 1001);

    sieveInit();

    int n;
    scanf("%d", &n);

    printf("N la so nguyen to? %d\n", isPrimeNumber(n));

    printPrimeNumberInRange(2, 1000);
}

int sieveInit() {
    for (int i = 2; i <= 1000; i++){
        for (int j = i + i; j <= 1000; j += i) {
            primeSieve[j] = 1;
        }
    }
}

int isPrimeNumber(int n) {
    return primeSieve[n] != 1;
}

void printPrimeNumberInRange(int startIndex, int endIndex) {
    int printedCount = 0;
    for (int i = startIndex; i <= endIndex; i++){
        if(isPrimeNumber(i)) {
            printf("%d ", i);
            printedCount++;
        }

        if(printedCount == 10){
            printedCount = 0;
            printf("\n");
        }
    }
}