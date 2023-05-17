#include <stdio.h>

int standardFactorial(int n, int step);

const int EVEN_STEP = 0, ODD_STEP = 1;

int main() {
    int n;
    scanf("%d", &n);
    printf("%d %d", standardFactorial(n, 1), standardFactorial(n, 2));
}

int standardFactorial(int n, int step) {
    if(n <= 1)
        return 1;
    return n * standardFactorial(n - step, step);
}
