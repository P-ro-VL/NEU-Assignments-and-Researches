#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int size(char *string);
void toUpper(char *string, int size);
void toLower(char *string, int size);
void reverse(char *string, int size);
void substring(char *string, int size, int endIndex);
void substrings(char *string, int size, int fromIndex, int endIndex);

const int STANDARD_STRING_SIZE = 100;

int main() {
    char *s[STANDARD_STRING_SIZE];
    for (int i = 0; i < STANDARD_STRING_SIZE; i++) {
        s[i] = 0;
    }
    gets(s);
    printf("str1 = %s\n", s);

    int SIZE = size(s);

    toUpper(s, SIZE);
    toLower(s, SIZE);
    reverse(s, SIZE);

    int m;
    scanf("%d", &m);
    substring(s, SIZE, m);

    int a, b;
    scanf("%d %d", &a, &b);
    substrings(s, SIZE, a, b);
}

int size(char *string){
    for (int i = STANDARD_STRING_SIZE - 1; i >= 0; i--)
    {
        if(string[i] != 0){
            return i + 1;
        }
    }
    return 0;
}

void toUpper(char *string, int size) {
    for (int i = 0; i < size; i++) {
        char value = string[i];
        if(value >= 97 && value <= 122){
            printf("%c", value - 32);
        }else{
            printf("%c", value);
        }
    }
    printf("\n");
}

void toLower(char *string, int size) {
    for (int i = 0; i < size; i++) {
        char value = string[i];
        if(value >= 65 && value <= 90){
            printf("%c", value + 32);
        }else{
            printf("%c", value);
        }
    }
    printf("\n");
}

void reverse(char *string, int size) {
    for (int i = size - 1; i >= 0; i--) {
        char value = string[i];
        printf("%c", value);
    }
    printf("\n");
}

void substring(char *string, int size, int endIndex) {
    for (int i = 0; i < endIndex; i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}

void substrings(char *string, int size, int fromIndex, int endIndex) {
    for (int i = fromIndex - 1; i < endIndex; i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}
