#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    char samples[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70};

    char bits[8];
    for (int i = 7; i >= 0; i--){
        bits[i] = samples[n % 16];
        n /= 16;
    }

    for (int i = 0; i < 8; i ++)
        printf("%c", bits[i]);
}