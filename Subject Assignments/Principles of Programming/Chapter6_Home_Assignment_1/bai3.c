#include <stdio.h>
#include <string.h>

void init();
int isPerfectSquare(int n);
void print();

int main() {
    init();

    int n;
    scanf("%d", &n);
    printf("La so chinh phuong: %d\n", isPerfectSquare(n));

    print();
}

int squares[1000001];

void init() {
    memset(squares, 0, 1000001);
    for (int i = 1; i <= 1000; i++){
        squares[i*i] = 1;
    }
}

int isPerfectSquare(int n){
    return squares[n];
}

void print() {
    int count = 0;
    for (int i = 1; i <= 1000; i++){
        if(isPerfectSquare(i)) {
            printf("%d ", i);
            count++;
        } 

        if(count == 15){
            count = 0;
            printf("\n");
        }
    }
}