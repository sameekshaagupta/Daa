#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char **matrix;
    int size;
} Matrix;

Matrix createMatrix(int n) {
    Matrix m = {NULL, n};
    m.matrix = (char **)malloc(m.size * sizeof(char *));
    for (int i = 0; i < m.size; i++) {
        m.matrix[i] = (char *)malloc(m.size * sizeof(char));
    }
    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            m.matrix[i][j] = '.';
        }
    }
    return m;
}

bool isSafe(int row, int col, Matrix *board) {
    // check column above the cell
    for (int i = row - 1; i > -1; i--) {
        if (board->matrix[i][col] == 'Q')
            return false;
    }
    // check left diagonal above cell
    for (int i = row - 1, j = col - 1; i > -1 && j > -1; i--, j--) {
        if (board->matrix[i][j] == 'Q')
            return false;
    }
    // check right diagonal above cell
    for (int i = row - 1, j = col + 1; i > -1 && j < board->size; i--, j++) {
        if (board->matrix[i][j] == 'Q')
            return false;
    }
    return true;
}

int backtrack(int row, Matrix *board, int n, int count) {
    if (n == 0) {
        printf("\n");
        for (int i = 0; i < board->size; i++) {
            for (int j = 0; j < board->size; j++) {
                printf("%c ", board->matrix[i][j]);
            }
            printf("\n");
        }
        return count + 1;
    }
    for (int i = row; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (isSafe(i, j, board)) {
                board->matrix[i][j] = 'Q';//recursive
                count = backtrack(i + 1, board, n - 1, count);
                board->matrix[i][j] = '.';
            }
        }
    }
    return count;
}

int main() {
    int n;
    printf("--Sameeksha Gupta 22BCP343-\n");
    printf("Enter number of queens: ");
    scanf("%d", &n);
    Matrix board = createMatrix(n);
    int count = backtrack(0, &board, n, 0);
    printf("\nNumber of solutions is: %d", count);
    return 0;
}