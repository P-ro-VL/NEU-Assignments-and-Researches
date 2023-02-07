#include <stdio.h>

int main(){
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int d, m, y;
    scanf("%d %d %d", &d, &m, &y);
    if(y % 4 == 0) daysInMonth[1] = 29;

    int pos = 0;
    for(int i = 0; i < m - 1; i++){
        pos += daysInMonth[i];
    }
    pos += d;

    printf("%d", pos);

    return 0; 
}