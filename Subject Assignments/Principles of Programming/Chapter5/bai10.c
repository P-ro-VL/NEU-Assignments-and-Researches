#include <stdio.h>

int main() {
    float x, y;
    char operation;

    scanf("%f %f %c", &x, &y, &operation);
    switch (operation)
    {
    case '+':
        printf("%f", x + y);
        break;
    case '-':
        printf("%f", x - y);
        break;
    case '*':
        printf("%f", x * y);
        break;
    case '/':
        if(y == 0){
            printf("Khong chia duoc.");
            break;
        }
        printf("%f", x / (y*1.0));
        break;
    default:
        break;
    }
}