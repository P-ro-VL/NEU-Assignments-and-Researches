#include <stdio.h>

int main() {
    char *canChi[10] = {"Canh", "Tan", "Nham", "Quy", "Giap", "At", "Binh", "Dinh", "Mau", "Ky"};
    char *conGiap[12] = {"Than", "Dau", "Tuat", "Hoi", "Ty", "Suu", "Dan", "Mao", "Thin", "Ty", "Ngo", "Mui" };
    int y;
    scanf("%d", &y);
    printf("%s %s", canChi[y % 10], conGiap[y%12]);
}