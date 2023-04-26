#include <stdio.h>

int main() {
    char name[100];
    gets(name);

    int index = 0;
    for (int i = 99; i >= 0; i--)
        if(name[i] == ' ')
        {
            index = i + 1;
            break;
        }
    char splittedString[100];
    int slot = 0;
    for (int i = index; i < 100; i++){
        splittedString[slot] = name[i];
        slot++;
    }
    printf("%s", splittedString);
}