#include <stdio.h>

int size(char *string){
    for (int i = 99; i >= 0; i--)
    {
        if(string[i] != 0){
            return i + 1;
        }
    }
    return 0;
}

int main() {
    char s[100];
    for (int i = 0; i < 100; i++) {
        s[i] = 0;
    }
    gets(s);

    int SIZE = size(s);
    int j = SIZE - 1;
    for (int i = 0; i < SIZE; i++){
        if(s[i] != s[j]) {
            printf("Khong doi xung");
            return;
        }else{
            j--;
        }
    }
    printf("Doi xung");
}