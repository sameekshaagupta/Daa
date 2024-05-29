#include <stdio.h> 

  

  

struct License 

{ 

    int id; 

    float growth_rate; 

}; 

  

  

void swap(struct License *a, struct License *b) 

{ 

    struct License t = *a; 

    *a = *b; 

    *b = t; 

} 

  

  

int partition(struct License arr[], int low, int high) 

{ 

    float pivot = arr[high].growth_rate; 

    int i = (low - 1); 

  

    for (int j = low; j <= high - 1; j++) 

    { 

        if (arr[j].growth_rate > pivot) 

        { 

            i++; 

            swap(&arr[i], &arr[j]); 

        } 

    } 

    swap(&arr[i + 1], &arr[high]); 

    return (i + 1); 

} 

  

void quickSort(struct License arr[], int low, int high) 

{ 

    if (low < high) 

    { 

        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 

        quickSort(arr, pi + 1, high); 

    } 

} 

  

void buy_licenses(struct License licenses[], int n) 

{ 

    quickSort(licenses, 0, n - 1); 

    printf("Order to buy licenses: "); 

    for (int i = 0; i < n; i++) 

    { 

        printf("%d ", licenses[i].id); 

    } 

} 

  

int main() 

{ 

    printf("-Sameeksha Gupta 22BCP343--\n"); 

    int n; 

    printf("Enter the number of licenses: "); 

    scanf("%d", &n); 

  

    struct License licenses[n]; 

    printf("Enter the growth rates for each license:\n"); 

    for (int i = 0; i < n; i++) 

    { 

        licenses[i].id = i + 1; 

        printf("License %d: ", i + 1); 

        scanf("%f", &licenses[i].growth_rate); 

    } 

  

    buy_licenses(licenses, n); 

  

    return 0; 

} 