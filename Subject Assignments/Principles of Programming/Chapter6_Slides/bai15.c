#include <stdio.h>
#include <string.h>

int s;
long long int total;
long long int frac[101];

void initFrac() {
    long long int t = 1;
    for (int i = 1; i <= 100; i++)
    {
        t *= i;
        frac[i] = t;
    }
}

int sumarr(int *result, int index){
    int t = 0;
    for (int i = 0; i < index; i++){
        t += result[i];
    }
    return t;
}

void caculateTotal(int *result, int index){
    int count[s + 1];
    for (int i = 0; i < s+1; i++)
        count[i] = 0;

    for (int i = 0; i < index; i++)
    {
        count[result[i]]++;
    }

    long long int fracs = 1;
    for (int i = 0; i < s + 1; i++)
        if(count[i] != 0)
            fracs *= frac[count[i]];

    total += (frac[index] / fracs);
}

void fractor(int n, int left, int *result) {
    static int idresult = 0 ;
    static int fnex = 0 ;
    int sum = sumarr (result, idresult);
    int i ;
    for (i = left ; i <= s; i++, fnex = 0) {
        if (sum + i < n) {
            result[idresult++] = i ;
            fractor (n, fnex ? i + 1 : i, result) ;
        }
        else if (sum + i == n) {
            result[idresult++] = i ;
            caculateTotal (result, idresult) ; 
            idresult -= 2 ;
            fnex = 1 ;
            return ;
        }
    }
    idresult-- ;
}

int main() {
    initFrac();

    int n;
    scanf("%d %d", &n, &s);

    int result[101];
    memset(result, 0, 101);
    fractor(n, 1, result);

    printf("%lld", total);
}