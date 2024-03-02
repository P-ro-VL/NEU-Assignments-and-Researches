#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        long long n;
        scanf("%lli", &n);

        for(int k = 2; k < log2(n) + 1; k++) {
            long long MS = pow(2, k) - 1;
            if (n % MS == 0)
            {
                printf("%lld\n", ((int) n / MS));
                break;
            }
        }
    }

    return 0;
}