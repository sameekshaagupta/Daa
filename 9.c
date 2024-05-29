#include <stdio.h>
#include <limits.h>
#define N 10

int n;
int graph[N][N];
int minCost = INT_MAX;
int finalPath[N];

int calculateLB(int path[], int level, int visited[]) {
    int lb = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int minDist = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && graph[i][j] < minDist) {
                    minDist = graph[i][j];
                }
            }
            lb += minDist;
        }
    }
    return lb;
}

void tsp(int level, int cost, int path[], int visited[]) {
    if (level == n) {
        if (graph[path[level - 1]][0] != 0) {
            int totalCost = cost + graph[path[level - 1]][0];
            if (totalCost < minCost) {
                minCost = totalCost;
                for (int i = 0; i < n; i++) {
                    finalPath[i] = path[i];
                }
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[path[level - 1]][i] != 0) {
            visited[i] = 1;
            path[level] = i;
            int lowerBound = calculateLB(path, level, visited);
            if (cost + graph[path[level - 1]][i] + lowerBound < minCost) {
                tsp(level + 1, cost + graph[path[level - 1]][i], path, visited);
            }
            visited[i] = 0;
        }
    }
}

int main() {
    printf("--Sameeksha Gupta 22BCP343-\n");
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distances between the cities in the format 'source city, destination city, distance':\n");

    int source, destination, distance;
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        scanf("%d %d %d", &source, &destination, &distance);
        graph[source][destination] = distance;
        graph[destination][source] = distance;
    }

    int path[N], visited[N] = {0};
    path[0] = 0;
    visited[0] = 1;

    tsp(1, 0, path, visited);

    printf("The minimum cost of the tour is: %d\n", minCost);
    printf("The tour path is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", finalPath[i]);
    }
    printf("%d\n", finalPath[0]);

    return 0;
}
