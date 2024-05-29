#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
    return (a>b) ? a : b;
}

typedef struct object{
    int impact;
    int cost;
    int qty;
    int price;
}obj;

void Knapsack(obj *arr,int n, int maxWt){

    int da[n+1][maxWt+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=maxWt;j++){
            if( i==0 || j==0 ){
                da[i][j]=0;
            }
            else if( arr[i].price <= j){
                da[i][j]=max(arr[i].impact+da[i-1][j-arr[i].price],da[i-1][j]);
            }
            else{
                da[i][j]=da[i-1][j];
            }
        }
    }

    printf("%d",da[n][maxWt]);
}

int main(){
    int n;
    printf("enter number of items : ");
    scanf("%d",&n);
    int maxWt;
    printf("enter maximum budget : ");
    scanf("%d",&maxWt);

    obj *arr = malloc(n+1 * (sizeof(obj)));
    
    for (int i = 0;i<=n;i++){
        if(i==0){
            arr[i].price=0;
            arr[i].impact=0;
        }
        else{
        printf("enter impact : ");
        scanf("%d",&arr[i].impact);
        printf("enter cost : ");
        scanf("%d",&arr[i].cost);
        printf("enter qty : ");
        scanf("%d",&arr[i].qty);
        arr[i].price=arr[i].cost*arr[i].qty;
        }
    }

    Knapsack(arr,n,maxWt);
    return 0;

}