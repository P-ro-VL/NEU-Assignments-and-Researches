#include <stdio.h>

typedef struct 
{
    char SBD[11];
    char Name[31];
    float Score;
} Candidate;

void sortByName();

int nextIndex = 0;
Candidate candidates[1000];

int main() {
    int n;

    printf(">> Nhap vao so luong thi sinh: ");
    scanf("%d", &n);

    printf(">> Nhap thong tin cac thi sinh:\n");
    for (int i = 0; i < n; i++) {
        Candidate thisinh;

        printf("- Thi sinh thu %d:\n", i + 1);
        printf("\t SBD: ");
        fflush(stdin);
        gets(thisinh.SBD);
        printf("\t Ho va ten: ");
        fflush(stdin);
        gets(thisinh.Name);
        printf("\t Diem thi: ");
        fflush(stdin);
        scanf("%f", &thisinh.Score);

        candidates[nextIndex] = thisinh;
        nextIndex++;
    }

    FILE *file = fopen("thisinh.txt", "w");
    fprintf(file, "%d\n", n);
    for (int i = 0; i < nextIndex; i++) {
        Candidate thisinh = candidates[i];
        fprintf(file, "%s\n%s\n%.4f\n", thisinh.SBD, thisinh.Name, thisinh.Score);
    }
    fclose(file);

    sortByName();
    FILE *sortedFile = fopen("thisinh_sx.txt", "w");
    fprintf(sortedFile, "%d\n", n);
    for (int i = 0; i < nextIndex; i++) {
        Candidate thisinh = candidates[i];
        fprintf(sortedFile, "%s\n%s\n%.4f\n", thisinh.SBD, thisinh.Name, thisinh.Score);
    }
    fclose(sortedFile);

    printf(">> Saved files.");
}

void sortByName() {
    for (int i = 0; i < nextIndex; i++) {
        for (int j = 0; j < nextIndex; j++) {
            if(candidates[i].Name[0] < candidates[j].Name[0]) {
                Candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }
}