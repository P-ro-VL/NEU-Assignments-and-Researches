#include <stdio.h>
#include <conio.h>

int main() {
    int result[3] = {0,0,0};
    int input[3] = {0, 0, 0};
    scanf("%c %c %c", &input[0], &input[1], &input[2]);

    for (int i = 0; i < 3; i++){
        int value = input[i];
        switch (value)
        {
        case 'B':
            ++result[0];
            break;
        case 'K':
            ++result[1];
            break;
        case 'G':
            ++result[2];
            break;
        }
    }

    char winner = '_';
    if (result[0] != 2 && result[1] != 2 && result[2] != 2){
        printf("DRAW");
        return 0;
    } else {
        if(result[0] == 2){
            if(result[1] == 1){
                winner = 'B';
            }else{
                winner = 'G';
            }
        }else if(result[1] == 2){
            if(result[2] == 1){
                winner = 'K';
            }else{
                winner = 'B';
            }
        }else{
            if(result[0] == 1){
                winner = 'G';
            }else{
                winner = 'K';
            }
        }
    }
    printf("WINNERS: \n");
    for (int i = 0; i < 3; i++)
        if(input[i] == winner)
            printf("- Player %d\n", i + 1);
}