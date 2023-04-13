#include <stdio.h>

int main() {
    int yourLeft, yourRight, friendLeft, friendRight;
    scanf("%d %d %d %d", &yourLeft, &yourRight, &friendLeft, &friendRight);

    printf(((yourLeft == friendLeft && yourRight == friendRight) || 
    (yourLeft == friendRight && yourRight == friendLeft)) ? 
    "Khoe nhu nhau" : "Khong khoe nhu nhau");
}