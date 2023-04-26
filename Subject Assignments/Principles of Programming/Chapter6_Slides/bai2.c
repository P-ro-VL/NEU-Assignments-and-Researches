#include <stdio.h>

void inputInteger(int *n){
    scanf("%d", n);
}

void inputReal(float *n){
    scanf("%f", n);
}

int main() {
    int n;
    inputInteger(&n);

    float m;
    inputReal(&m);
}