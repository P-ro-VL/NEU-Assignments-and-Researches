#include <stdio.h>

int main() {
    for (int i = 0; i <= 20; i++)
        for (int j = 0; j <= 10; j++)
            for (int k = 0; k <= 4; k++)
                if(10*i + 20*j + 50*k == 200)
                    printf("%d to 10k, %d to 20k, %d to 50k\n", i, j, k);
}