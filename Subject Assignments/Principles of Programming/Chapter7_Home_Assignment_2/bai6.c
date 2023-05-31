#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    memset(s, 0, 100);
    gets(s);

    int nguyenAm = 0, phuAm = 0;
    for (int i = 0; i < 100; i++) {
        if(s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'a' || s[i] == 'i'){
            nguyenAm++;
        }else if(s[i] == 'U' || s[i] == 'E' || s[i] == 'O' || s[i] == 'A' || s[i] == 'I'){
            nguyenAm++;
        }else if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
            phuAm++;
        }
    }
    printf("So nguyen am = %d; so phu am = %d", nguyenAm, phuAm);
}