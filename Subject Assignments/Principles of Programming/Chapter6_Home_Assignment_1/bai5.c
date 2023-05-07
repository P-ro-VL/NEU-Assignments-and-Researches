#include <stdio.h>

void readMatrixSize();
void readMatrixElements();
void sortMatrix(int sortMode, int isAscending);
void printMatrix();

void sortArray(float *array, int isAscending);

int SORT_ROWS = 0, SORT_COLUMN = 1;

int main() {
    readMatrixSize();
    readMatrixElements();
    printf("Inputed matrix:\n");
    printMatrix();
    sortMatrix(SORT_ROWS, 1);
    printf("Ascending Rows Sorted:\n");
    printMatrix();
    sortMatrix(SORT_COLUMN, 0);
    printf("Descending Columns Sorted:\n");
    printMatrix();
}

int m, n;
float matrix[50][50];

void readMatrixSize() {
    scanf("%d %d", &m, &n);
}

void readMatrixElements() {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            printf("Input the element at [%d,%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
        }
}

void sortMatrix(int sortMode, int isAscending){
    float array[m * n];
    int index = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            array[index] = matrix[i][j];
            index++;
        }
    index = 0;

    sortArray(array, isAscending);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            if(sortMode == SORT_ROWS){
                matrix[i][j] = array[index];
            }else{
                matrix[j][i] = array[index];
            }
            index++;
        }
}

void printMatrix(){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
        {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void sortArray(float *array, int isAscending) {
    for (int i = 0; i < m*n; i++)
        for (int j = 0; j < m*n; j++)
            if(isAscending ? array[i] < array[j] 
                    : array[i] > array[j]){
                float temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}