#include<stdio.h>
#include<string.h>
 
void print(int *num, int n)
{
    for (int i = 0; i < n ; i++)
        printf("%d ", num[i]);
    printf("\n");
}

int main()
{
    int temp;
    int i, n, j;
    scanf("%d", &n);
    int num[n];
    for (i = 0 ; i < n; i++)
        scanf("%d", &num[i]);
    for (j = 1; j <= n; j++) {
        for (i = 0; i < n-1; i++) {
            temp = num[i];
            num[i] = num[i+1];
            num[i+1] = temp;
            print(num, n);
	    }
    }
    return 0;
}