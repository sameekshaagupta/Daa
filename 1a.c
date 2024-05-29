#include<stdio.h>  

  

void BubbleSort(int a[],int n){  

  int i,j;  

   for(int i=0;i<n;i++){  

     for(int j=0;j<n-i-1;j++){  

      if(a[j]>a[j+1]){  

         int t=a[j];  

         a[j]=a[j+1];  

         a[j+1]=t;  

       }  

    }  

  }  

 }  

  

int main() {    

   printf("—Sameeksha Gupta  22BCP343--\n");  

  int n;  

  printf("Enter the elements you want:");  

   scanf("%d",&n);  

   int a[n]; 

   for(int i=0;i<n;i++){  

    printf("Enter the %d number: ",i+1);  

    scanf("%d",&a[i]);  

   }  

   BubbleSort(a, n);    

  printf("Sorted array: ");    

      for (int i = 0; i < n; i++)  

        printf("%d ", a[i]);  

    printf("\n");  

   return 0;    

 }    