#include <stdio.h>
#include <string.h>

typedef struct 
{
    char SBD[11];
    char Name[31];
    float Score;
} Candidate;

void sortByAscendingScore();

int nextIndex = 0;
Candidate candidates[1000];

int main() {
    FILE *file = fopen("thisinh.txt", "r");

    int n;
    fscanf(file, "%d\n", &n);

    for (int i = 0; i < n; i++) {
        Candidate thisinh;

        fflush(stdin);
        fgets(thisinh.SBD, 100, file);
        fflush(stdin);
        fgets(thisinh.Name, 100, file);
        fflush(stdin);
        fscanf(file, "%f\n", &thisinh.Score);

        thisinh.SBD[strlen(thisinh.SBD) - 1] = '\0';
        thisinh.Name[strlen(thisinh.Name) - 1] = '\0';

        candidates[nextIndex] = thisinh;
        nextIndex++;
    }

    printf("|---|----------|------------------------------|-----|\n");
    printf("|STT|   SBD    |           HO VA TEN          |DIEM |\n");
    printf("|---|----------|------------------------------|-----|\n");

    for (int i = 0; i < nextIndex; i++) {
        Candidate thisinh = candidates[i];
        printf("|%-3d|%-10s|%-30s|%-5.2f|\n",
               i + 1,
               thisinh.SBD,
               thisinh.Name,
               thisinh.Score);
    }
    printf("|---|----------|------------------------------|-----|\n");

    sortByAscendingScore();
    FILE *sortedFile = fopen("thisinh2.txt", "w");
    fprintf(sortedFile, "%d\n", n);
    for (int i = 0; i < nextIndex; i++) {
        Candidate thisinh = candidates[i];
        fprintf(sortedFile, "%s\n%s\n%.4f\n", thisinh.SBD, thisinh.Name, thisinh.Score);
    }
    fclose(sortedFile);

    printf(">> Saved files.");
}

void sortByAscendingScore() {
    for (int i = 0; i < nextIndex; i++) {
        for (int j = 0; j < nextIndex; j++) {
            if(candidates[i].Score > candidates[j].Score) {
                Candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }
}
