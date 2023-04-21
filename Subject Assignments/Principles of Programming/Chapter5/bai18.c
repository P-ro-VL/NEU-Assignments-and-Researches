#include <stdio.h>

int main() {
    for (int i = 1; i <= 36; i++)
        for (int j = 1; j <= 36 - i; j++)
            if(i+j == 36 && i*4+j*2==100)
                printf("Co %d cho va %d ga\n", i, j);
}