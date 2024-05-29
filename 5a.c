#include <stdio.h>
void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {

        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    printf("--Sameeksha Gupta 22BCP343\n");
    printf("Enter size of array: ");
    int m;
    scanf("%d", &m);
    int arr[m];
    printf("Enter values in array: ");
    for(int i = 0; i<m ; i++){
        scanf("%d", &arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    printf("Sorted array is \n");
    printArray(arr, n);
}
