#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array[100];
int n;

void a(){
    printf("a) Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void b(){
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += array[i];
    printf("b) Sum: %d\n", sum);
}

void c() {
    int min = 999999, max = -999999, minIndex = 0, maxIndex = 0;
    for (int i = 0; i < n; i++){
        int v = array[i];
        if(v > max){
            max = v;
            maxIndex = i;
        }

        if(v < min){
            min = v;
            minIndex = i;
        }
    }

    printf("c) Min/MinIndex Max/MaxIndex: %d/%d %d/%d\n", min, minIndex, max, maxIndex);
}

void d(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(array[j] > array[i])
            {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
    
    printf("d) Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void e() {
    int count = 0;
    int data[10000];
    memset(data, 0, 10000);
    for (int i = 0; i < n; i++){
        data[array[i]] = 1;
    }

    for (int j = 0; j < 10000; j++)
        if(data[j] == 1)
            count++;
    
    printf("d) Different Element Count: %d\n", count);
}

void f() {
    int odd[n], even[n];
    int oddCount = 0, evenCount = 0;
    for (int i = 0; i < n; i++)
        if(array[i] % 2 == 0){
            even[evenCount] = array[i];
            evenCount++;
        }else{
            odd[oddCount] = array[i];
            oddCount++;
        }
    printf("f) Odd: ");
    for (int i = 0; i < oddCount; i++){
        printf("%d ", odd[i]);
    }

    printf("\nEven: ");
    for (int i = 0; i < evenCount; i++){
        printf("%d ", even[i]);
    }
}

void g() {
    printf("\ng) InsertIndex InsertValue: ");
    int insertIndex, insertValue;
    scanf("%d %d", &insertIndex, &insertValue);

    n++;
    for (int i = insertIndex + 1; i < n; i++){
        int temp = array[i];
        array[i] = array[insertIndex];
        array[insertIndex] = temp;
    }

    array[insertIndex] = insertValue;
    printf("Inserted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void h() {
    printf("g) DeleteIndex: ");
    int deleteIndex;
    scanf("%d", &deleteIndex);

    int toSwapIndex = deleteIndex;
    for (int i = deleteIndex + 1; i < n; i++){
        int temp = array[i];
        array[i] = array[toSwapIndex];
        array[toSwapIndex] = temp;
        toSwapIndex++;
    }
    n--;

    printf("Deleted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void i() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(array[j] > array[i])
            {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
    printf("i) Second max value: %d", array[n - 2]);
}

void j() {
    int row = 0, column = 0;
    int minValue = 999999;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i == j)
                continue;
            int sum = abs(array[i] + array[j]);
            if(sum < minValue){
                minValue = sum;
                row = i;
                column = j;
            }
        }
    }

    printf("\nj) Sum approximate zero: %d %d", array[row], array[column]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int value;
        scanf("%d", &value);
        array[i] = value;
    }
    a();
    b();
    c();
    d();
    e();
    f();
    g();
    h();
    i();
    j();
}