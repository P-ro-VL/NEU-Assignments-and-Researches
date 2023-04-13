#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
    char characters[1000];
    int frequency[128];

    memset(characters, -1, sizeof(characters));
    memset(frequency, 0, sizeof(frequency));

    scanf("%s", &characters);

    char c;
    int index = 0;
    while((c = characters[index]) != -1){
        frequency[c]++;
        index++;
    }

    int oddCount = 0;
    for (int i = 65; i < 123; i++){
        int value = frequency[i];

        if(value % 2 != 0){
            oddCount++;
        }
    }
    
    if(oddCount > 1){
        printf("Khong duoc");
    }else{
        printf("Ok");
    }
}