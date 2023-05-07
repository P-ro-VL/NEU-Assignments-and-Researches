#include <stdio.h>

void readArraySize();
void readArrayElements();
void printArray();
void sortArray();

int main() {
    readArraySize();
    readArrayElements();
    sortArray();
    printArray();
}

int n;
float array[50];

void readArraySize() {
    scanf("%d", &n);
}

void readArrayElements() {
    for (int i = 0; i < n; i++){
        scanf("%f", &array[i]);
    }
}

void sortArray() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(array[i] > array[j]){
                float temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}

void printArray() {
    for (int i = 0; i < n; i++){
        printf("%f ", array[i]);
    }
}