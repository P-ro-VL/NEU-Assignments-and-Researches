#include <stdio.h>

int main() {
    int hour, salary;
    scanf("%d %d", &hour, &salary);
    int bonusHour = hour - 40;
    hour = bonusHour > 0 ? 40 : hour;
    int bonusSalary = bonusHour > 0 ? bonusHour * 1.5 * salary : 0;
    printf("%d", hour * salary + bonusSalary);
}