#include <stdio.h>

int main() {
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            for (int k = 1; k <= 100; k++)
                if (i + j + k == 100 && i * 15 + j * 9 + k == 300)
                    printf("Co %d trau dung, %d trau nam va %d trau gia\n", i, j, k);
}