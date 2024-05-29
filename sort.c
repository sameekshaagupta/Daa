CODE: 

#include<stdio.h> 

#include<stdlib.h> 

  

int *count_sort(int *arr, int size, int exponent) { 

    int *f_a ; 

    f_a = (int*)malloc(sizeof(int) * 10); 

    int sum = 0; 

  

    for(int i = 0; i < 10; i++) { 

        f_a[i]=0; 

    } 

  

    for(int i = 0; i < size; i++) { 

        f_a[(arr[i]/exponent) % 10]++; 

    } 

  

    for(int i = 0; i < 10; i++) { 

        sum = sum + f_a[i]; 

        f_a[i] = sum; 

    } 

  

    int *new_arr; 

    new_arr = (int*)malloc(sizeof(int) * size); 

    int pos; 

    for(int i = size-1; i >= 0; i--){ 

        pos = f_a[(arr[i]/exponent)%10]-1; 

        new_arr[pos] = arr[i]; 

        f_a[(arr[i]/exponent)%10]--; 

    } 

     

    return new_arr; 

} 

  

int maximum(int *arr, int length) { 

    int max=0; 

    for( int i = 0 ; i < length; i++) 

    { 

        if(arr[i]>max) 

            max=arr[i]; 

    } 

    return max; 

} 

  

int *radix_sort(int *arr, int size) 

{ 

    int max_ele = maximum(arr, size); 

    int exp = 1; 

    while(exp <= max_ele) 

    { 

        arr = count_sort(arr, size, exp); 

        exp = exp * 10; 

    } 

    return arr; 

} 

  

void main() { 

     

    printf("Sameeksha Gupta 22BCP343\n"); 

    int arrayLength; 

    printf("Enter Array Size : "); 

    scanf("%d", &arrayLength); 

  

    int inputArray[arrayLength]; 

    int *outputArray; 

    outputArray = (int*)malloc(sizeof(int) * arrayLength); 

  

    printf("Enter %d integers:\n", arrayLength); 

    for (int i = 0; i < arrayLength; i++) { 

        scanf("%d", &inputArray[i]); 

    } 

     

    printf("Original array: "); 

    for (int i = 0; i < arrayLength; i++) { 

        printf("%d ", inputArray[i]); 

    } 

  

    outputArray = radix_sort(inputArray, arrayLength); 

  

    printf("\nSorted array: "); 

    for (int i = 0; i < arrayLength; i++) { 

        printf("%d ", outputArray[i]); 

    } 

} 