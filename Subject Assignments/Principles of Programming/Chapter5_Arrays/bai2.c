#include <stdio.h>
int m, n;
float A[100][100], B[100][100], C[100][100];

void a() {
    printf("a) Inputed Matrix: \n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            printf("%.2f ", A[i][j]);
        printf("\n");
    }
}

void b() {
    float sum = 0.0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            sum += A[i][j];
    printf("b) Sum of the Matrix: %.2f\n", sum);
}

void c() {
    float min = 999999, max = -999999;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            float value = A[i][j];
            if(value < min){
                min = value;
            }

            if(value > max){
                max = value;
            }
        }
    printf("c) Min / Max: %.2f / %.2f\n", min, max);
}

void de() {
    float rowSum[m], colSum[n];
    for (int i = 0; i < m; i++)
    {
        float sum = 0.0;
        for (int j = 0; j < n; j++){
            sum += A[i][j];
        }
        rowSum[i] = sum;
    }

    for (int i = 0; i < m; i++)
    {
        float sum = 0.0;
        for (int j = 0; j < n; j++){
            sum += A[j][i];
        }
        colSum[i] = sum;
    }

    printf("\nd) Col Sums: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", colSum[i]);
    printf("\ne) Row Sums: ");
    for (int i = 0; i < m; i++)
        printf("%.2f ", rowSum[i]);
    
}

void f() {
    float toArrange[m * n];
    int index = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            toArrange[index] = A[i][j];
            index++;
        }

    for (int i = 0; i < m * n; i++)
        for (int j = 0; j < m * n; j++)
        {
            if(toArrange[i] < toArrange[j]){
                float temp = toArrange[j];
                toArrange[j] = toArrange[i];
                toArrange[i] = temp;
            }
        }

    index = 0;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            B[i][j] = toArrange[index];
            C[j][i] = toArrange[index];
            index++;
        }
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            printf("%.2f ", B[i][j]);
        printf("\n");
    }
    
    printf("\nMatrix C:\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            printf("%.2f ", C[i][j]);
        printf("\n");
    }

    printf("\nSum Matrix:\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
        {
            printf("%.2f ", B[i][j] + C[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Input the size of the matrix (m x n): ");
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            printf("\tInput the element at row %d col %d: ", i, j);
            scanf("%f", &A[i][j]);
        }

    a();
    b();
    c();
    de();
    f();
}