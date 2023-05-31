#include <stdio.h>
#include <string.h>

int main() {
    int values[128];
    for (int i = 0; i < 128; i++)
        values[i] = 0;

    char s[100];
    memset(s, 0, 100);
    gets(s);

    for (int i = 0; i < 100; i++){
        if(s[i] != 0) {
            values[s[i]]++;
        }
    }

    int count = 0;
    for (int i = 0; i < 128; i++) {
        if(values[i] != 0){
            count++;
            printf("So ky tu %c la %d\n", i, values[i]);
        }
    }
    printf("========================\n");
    printf("Tong so ky tu: %d", count);
}