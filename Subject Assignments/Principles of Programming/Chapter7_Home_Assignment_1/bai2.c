#include <stdio.h>

void readElements(int *a, int n) {
    for (int i = 0; i < n; i++){
        scanf("%d", *(a + i));
    }
}

void printElements(int *a, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", *(a + i));
    }
    printf("\n");
}

void sortAscending(int *a, int n){
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
}

int indexOf(int *a, int n, int m) {
    for (int i = 0; i < n; i++) {
        if(*(a + i) == m) { // pointer
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    readElements(n, a[n]);

    printf("Elements in array: ");
    printElements(a, n);

    sortAscending(a, n);

    printf("\nSorted Array: ");
    printElements(a, n);

    int m;
    scanf("%d", &m);
    if(indexOf(a, n, m) != -1) {
        printf("The array contains element %d", m);
    }
}