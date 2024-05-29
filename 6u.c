#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add_matrices(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int **allocate_matrix(int n) {
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    return matrix;
}

void standard_matrix_multiply(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void input_matrix(int **matrix, int n) {
    printf("Enter matrix values row by row:\n");
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Strassen's matrix multiplication algorithm
void strassen_matrix_multiply(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;

    int **A11 = allocate_matrix(newSize);
    int **A12 = allocate_matrix(newSize);
    int **A21 = allocate_matrix(newSize);
    int **A22 = allocate_matrix(newSize);
    int **B11 = allocate_matrix(newSize);
    int **B12 = allocate_matrix(newSize);
    int **B21 = allocate_matrix(newSize);
    int **B22 = allocate_matrix(newSize);
    int **C11 = allocate_matrix(newSize);
    int **C12 = allocate_matrix(newSize);
    int **C21 = allocate_matrix(newSize);
    int **C22 = allocate_matrix(newSize);

    // Partitioning input matrices into submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    int **temp1 = allocate_matrix(newSize);
    int **temp2 = allocate_matrix(newSize);

    // Strassen's recursive calls
    standard_matrix_multiply(A11, B11, temp1, newSize);
    standard_matrix_multiply(A12, B21, temp2, newSize);
    add_matrices(temp1, temp2, C11, newSize);

    standard_matrix_multiply(A11, B12, temp1, newSize);
    standard_matrix_multiply(A12, B22, temp2, newSize);
    add_matrices(temp1, temp2, C12, newSize);

    standard_matrix_multiply(A21, B11, temp1, newSize);
    standard_matrix_multiply(A22, B21, temp2, newSize);
    add_matrices(temp1, temp2, C21, newSize);

    standard_matrix_multiply(A21, B12, temp1, newSize);
    standard_matrix_multiply(A22, B22, temp2, newSize);
    add_matrices(temp1, temp2, C22, newSize);

    // Combining submatrices into the result matrix
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main() {
    int n;
    int **A, **B, **C_standard, **C_strassen;
    printf("Sameeksha Gupta 22BCP343\n");
    printf("-- Matrix Multiplication --\n");
    printf("Enter size of matrices: ");
    scanf("%d", &n);

    A = allocate_matrix(n);
    B = allocate_matrix(n);
    C_standard = allocate_matrix(n);
    C_strassen = allocate_matrix(n);

    printf("Input values for matrix A:\n");
    input_matrix(A, n);
    printf("Input values for matrix B:\n");
    input_matrix(B, n);

    // Standard matrix multiplication
    clock_t start_standard = clock();
    standard_matrix_multiply(A, B, C_standard, n);
    clock_t end_standard = clock();
    double time_standard = ((double)(end_standard - start_standard)) / CLOCKS_PER_SEC;

    // Strassen's matrix multiplication
    clock_t start_strassen = clock();
    strassen_matrix_multiply(A, B, C_strassen, n);
    clock_t end_strassen = clock();
    double time_strassen = ((double)(end_strassen - start_strassen)) / CLOCKS_PER_SEC;

    printf("\nResult Matrix C (Standard Multiplication):\n");
    print_matrix(C_standard, n);
    printf("\nResult Matrix C (Strassen's Multiplication):\n");
    print_matrix(C_strassen, n);

    printf("\nTime taken for standard multiplication: %f seconds\n", time_standard);
    printf("Time taken for Strassen's multiplication: %f seconds\n", time_strassen);

    // Determining threshold value for Strassen's algorithm
    printf("\nThreshold value for Strassen's algorithm:\n");
    printf("For n > %d, Strassen's algorithm becomes more efficient.\n", (int)(pow(2, 14)));

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C_standard[i]);
        free(C_strassen[i]);
    }
    free(A);
    free(B);
    free(C_standard);
    free(C_strassen);

    return 0;
}
