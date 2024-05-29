#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int id;
    int type;
    int cost;
    int quantity;
} Item;

int comapre(const void* a, const void* b){
    if(((Item *)a)->cost - ((Item *)b)->cost < 0){
        return -1;
    }
    else if(((Item *)a)->cost - ((Item *)b)->cost < 0){
        return 0;
    }
    else{
        return 1;
    }
}

int maxItems(Item* items, int n, int budget){
    qsort(items, n , sizeof(Item), comapre);

    int remainingBudget = budget;
    int totalQuantity = 0;

    for(int i =0; i<n; i++){
        if(remainingBudget >= items[i].cost){
            int quantityToBuy = (remainingBudget/ items[i].cost);
            if(quantityToBuy >= items[i].quantity){
                quantityToBuy = items[i].quantity;
                remainingBudget -= quantityToBuy*items[i].cost;
                totalQuantity += quantityToBuy;
                printf("Item id: %d, Item type: %d\n", items[i].id, items[i].type);
            }
        }
    }
    printf("Total quantity of items bought: %d\n", totalQuantity);
    return totalQuantity;
}

int main(){
    int n, budget;

    printf("Enter the total number of items(Food + Decorations) : ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item));

    printf("Enter item details: \n");
    for(int i = 0; i< n; i++){
        printf("type 0 for food type 1 for decoration ");
        printf("Item %d (type, cost, quantity): ", i+1 );
        scanf("%d %d %d", &items[i].type, &items[i].cost, &items[i].quantity);
        items[i].id = i + 1;
    }

    printf("\nWhat is your budget?\n");
    scanf("%d", &budget);

    maxItems(items, n, budget);

    free(items);
    return 0;
}