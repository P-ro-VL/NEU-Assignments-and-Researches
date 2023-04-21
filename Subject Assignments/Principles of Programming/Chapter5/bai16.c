#include <stdio.h>
#include <conio.h>

int main() {
    char c;
    while(c != '0'){
        c = getchar();
        printf("%d\n", c);
        fflush(stdin);
    }
}