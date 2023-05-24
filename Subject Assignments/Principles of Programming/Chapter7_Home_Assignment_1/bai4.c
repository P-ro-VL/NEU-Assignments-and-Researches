#include <stdio.h>

int main() {
    char *a = 'A' - 1;
    do {
        a++;
        printf("%c ", a);
    } while (a != 'Z');
}