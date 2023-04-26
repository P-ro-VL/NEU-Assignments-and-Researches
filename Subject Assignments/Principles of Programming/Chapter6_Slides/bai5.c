#include <stdio.h>

int min(int a, int b){
    return a >= b ? b : a;
}

int isLetter(char c){
    return (65 <= c && c <= 90) || (97 <= c && c <= 122);
}

char toUpperCase(char c){
    if(!isLetter(c) || (65 <= c && c <= 90))
        return c;
    return c - 32;
}

char toLowerCase(char c){
    if(!isLetter(c) || (97 <= c && c <= 122))
        return c;
    return c + 32;
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
            s[nextIndex] = toUpperCase(s[nextIndex]);
            capitalizedString[index] = ' ';
            capitalizedString[index + 1] = s[nextIndex];
            index += 2;
            i += 1;
            continue;
        }
        capitalizedString[index] = toLowerCase(s[i]);
        index++;
    }
    capitalizedString[0] = capitalizedString[0] - 32;

    printf("%s", capitalizedString);
}