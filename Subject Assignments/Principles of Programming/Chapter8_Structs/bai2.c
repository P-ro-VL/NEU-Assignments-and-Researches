#include <stdio.h>

typedef struct
{
    char name[100];
    int win;
    int draw;
    int lose;
} DoiBong;

int nextIndex = 0;
DoiBong teams[100];

int findWinner();

int main()
{
    printf("Enter the number of football teams: ");
    int n;
    scanf("%d", &n);

    while(n--){
        DoiBong footballTeam;
        printf(">> Football Team %d:", (nextIndex + 1));
        fflush(stdin);
        printf("\n\tName: ");
        gets(footballTeam.name);
        fflush(stdin);
        printf("\tWin - Draw - Lose: ");
        scanf("%d %d %d", &footballTeam.win, &footballTeam.draw, &footballTeam.lose);

        teams[nextIndex] = footballTeam;
        nextIndex++;
    }

    int maxIndex = findWinner();
    printf("The winner football team is %s.", teams[maxIndex].name);

    return 0;
}

int findWinner() {
    int scores[100];

    int maxIndex = 0;
    int maxScore = -999999;
    for (int i = 0; i < nextIndex; i++) {
        DoiBong footballTeam = teams[i];
        int value = footballTeam.win * 3 + footballTeam.draw;
        if(value > maxScore) {
            maxScore = value;
            maxIndex = i;
        }
    }

    return maxIndex;
}
