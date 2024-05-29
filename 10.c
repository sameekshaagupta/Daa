#include <stdio.h> 

  

void find_p(int array[], int start, int end) 

{ 

    if (start == end) 

    { 

        printf("Peak value is: %d\n", array[start]); 

        return; 

    } 

  

    int mid = start + (end - start) / 2; 

  

    if (array[mid] > array[mid + 1]) 

        find_p(array, start, mid); 

    else 

        find_p(array, mid + 1, end); 

} 

  

int main() 

{ 

    printf("Name: Sameeksha Gupta\nRoll No.: 22BCP343\n"); 

    int n = 0; 

    printf("Enter number of elements of array: "); 

    scanf("%d", &n); 

  

    int array[n]; 

    printf("Enter numbers: "); 

    for (int i = 0; i < n; i++) 

    { 

        scanf("%d", &array[i]); 

    } 

  

    find_p(array, 0, n - 1); 

  

    return 0; 

} 