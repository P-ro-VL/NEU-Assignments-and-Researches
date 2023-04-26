#include <stdio.h>

int isLetter(char c){
    return (65 <= c && c <= 90) || (97 <= c && c <= 122);
}

int min(int a, int b){
    return a >= b ? b : a;
}

int main() {
    char s[100];
    gets(s);
    char capitalizedString[100];

    int startIndex = 0, endIndex = 99;
    while(!(isLetter(s[startIndex]) && isLetter(s[endIndex]))){
        if(!isLetter(s[startIndex]))
            startIndex++;
        if(!isLetter(s[endIndex]))
            endIndex--;
    }

    int index = 0;
    for (int i = startIndex; i <= endIndex; i++){
        if(s[i] == ' '){
            int nextIndex = min(99, i+1);
            if(!isLetter(s[nextIndex]))
                continue;
            capitalizedString[index] = ' ';
            capitalizedString[index + 1] = s[nextIndex];
            index += 2;
            i += 1;
            continue;
        }
        capitalizedString[index] = s[i];
        index++;
    }

    int spaceCount = 0;
    for (int i = 0; i < 100; i++){
        if(capitalizedString[i] == ' ')
            spaceCount++;
    }

    printf("%d", spaceCount + 1);
}