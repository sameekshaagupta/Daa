#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cost;
    int quantity;
    float returns;
} Asset;

int max(int a, int b) {
    return (a > b) ? a : b;
}

float maxReturns(int n, Asset *assets, int budget, int months) {
    float dp[budget + 1][months + 1];

    for (int i = 0; i <= budget; i++) {
        for (int j = 0; j <= months; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = budget; j >= assets[i].cost; j--) {
            for (int t = 1; t <= months; t++) {
                if (assets[i].cost <= j && assets[i].quantity > 0) {
                    dp[j][t] = max(dp[j][t], assets[i].returns + dp[j - assets[i].cost][t - 1]);
                }
            }
        }
    }   

    return dp[budget][months];
}

int main() {
    int n;
    printf("Enter the number of assets: ");
    scanf("%d", &n);

    Asset *assets = malloc((n + 1) * sizeof(Asset));

    printf("Enter details for each asset:\n");
    for (int i = 1; i <= n; i++) {
        printf("Asset %d:\n", i);
        printf("Cost: ");
        scanf("%d", &assets[i].cost);
        printf("Quantity: ");
        scanf("%d", &assets[i].quantity);
        printf("Returns: ");
        scanf("%f", &assets[i].returns);
    }

    int budget, months;
    printf("Enter the maximum allocated budget: ");
    scanf("%d", &budget);
    printf("Enter the number of months: ");
    scanf("%d", &months);

    float result = maxReturns(n, assets, budget, months);
    printf("Maximum returns after %d months: %.2f\n", months, result);

    free(assets);
    return 0;
}