#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    
    for (int i = 0; i < n; i++){
        scanf("%d", a + i); // pointer
    }

    printf("Elements in array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", *(a + i)); // pointer
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if(a[j] < a[i]){
                // pointers start
                *(a + i) = *(a + i) + *(a + j);
                *(a + j) = *(a + i) - *(a + j);
                *(a + i) = *(a + i) - *(a + j);
                // pointers end
            }
        }
    }
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    int m;
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        if(*(a + i) == m) { // pointer
            printf("The array contains element %d", m);
            break;
        }
    }
}