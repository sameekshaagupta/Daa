#include <stdio.h>
#include <string.h>

#define INF 999

void printMatrix(int matrix[][100], int n);

// Implementing Floyd-Warshall algorithm
void floydWarshall(int graph[][100], int n) {
    int matrix[100][100], i, j, k;

    // Initialize matrix with the given graph
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            matrix[i][j] = graph[i][j];

    // Applying Floyd-Warshall algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    // Printing the shortest distances between every pair of vertices
    printMatrix(matrix, n);
}

void printMatrix(int matrix[][100], int n) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == INF)
                printf("%5s", "INF");
            else
                printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Sameeksha Gupta\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[100][100];

    printf("Enter the adjacency matrix (enter %d rows, each containing %d elements, use 'INF' for infinity):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char input[10];
            scanf("%s", input);

            if (strcmp(input, "INF") == 0)
                graph[i][j] = INF;
            else
                graph[i][j] = atoi(input);
        }
    }

    floydWarshall(graph, n);

    return 0;
}
