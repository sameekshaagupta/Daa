#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int id;
    int type;
    int cost;
    int quantity;
} Item;

// Comparison function for quicksort
int compare(const void* a, const void* b) {
    return ((Item*)a)->cost - ((Item*)b)->cost;
}

// Quicksort implementation
void quicksort(Item* items, int low, int high) {
    if (low < high) {
        int pivot = partition(items, low, high);
        quicksort(items, low, pivot - 1);
        quicksort(items, pivot + 1, high);
    }
}

// Partition function for quicksort
int partition(Item* items, int low, int high) {
    int pivot = items[high].cost;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (items[j].cost <= pivot) {
            i++;
            swap(&items[i], &items[j]);
        }
    }
    swap(&items[i + 1], &items[high]);
    return i + 1;
}

// Function to swap two items
void swap(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

int maxItems(Item* items, int n, int budget) {
    quicksort(items, 0, n - 1);

    int remainingBudget = budget;
    int totalQuantity = 0;

    for (int i = 0; i < n; i++) {
        if (remainingBudget >= items[i].cost) {
            int quantityToBuy = remainingBudget / items[i].cost;
            if (quantityToBuy >= items[i].quantity) {
                quantityToBuy = items[i].quantity;
                remainingBudget -= quantityToBuy * items[i].cost;
                totalQuantity += quantityToBuy;
                printf("Item id: %d, Item type: %d\n", items[i].id, items[i].type);
            }
        }
    }
    printf("Total quantity of items bought: %d\n", totalQuantity);
    return totalQuantity;
}

int main() {
    int n, budget;

    printf("Enter the total number of items (Food + Decorations): ");
    scanf("%d", &n);

    Item* items = (Item*)malloc(n * sizeof(Item));

    printf("Enter item details: \n");
    for (int i = 0; i < n; i++) {
        printf("Type 0 for food, Type 1 for decoration.\n");
        printf("Item %d (type, cost, quantity): ", i + 1);
        scanf("%d %d %d", &items[i].type, &items[i].cost, &items[i].quantity);
        items[i].id = i + 1;
    }

    printf("\nWhat is your budget?\n");
    scanf("%d", &budget);

    maxItems(items, n, budget);

    free(items);
    return 0;
}
