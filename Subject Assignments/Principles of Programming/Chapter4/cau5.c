#include <stdio.h>

int main() {
    float pi = 3.141592;
    float R;
    scanf("%f", &R);

    float S = 4 * pi * R * R;
    float V = (4.0 / 3.0) * pi * R * R * R;

    printf("S = %f\nV = %f", S, V);
}