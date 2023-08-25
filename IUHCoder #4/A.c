#include <stdio.h>

int main() {
    long long int oneX, oneY, twoX, twoY, threeX, threeY;
    scanf("%lld %lld\n", &oneX, &oneY);
    scanf("%lld %lld\n", &twoX, &twoY);
    scanf("%lld %lld", &threeX, &threeY);

    int checkX = oneX == twoX && twoX == threeX && oneX == threeX;
    int checkY = oneY == twoY && twoY == threeY && oneY == threeY;

    if(checkX || checkY) {
        printf("0");
        return 0;
    }

    checkX = oneX == twoX || twoX == threeX || oneX == threeX;
    checkY = oneY == twoY || twoY == threeY || oneY == threeY;
    if(checkX || checkY) {
        printf("1");
        return 0;
    }

    if((oneX < 0 && twoX < 0 && threeX < 0)) {
        printf("3");
        return 0;
    }

    printf("2");
}
