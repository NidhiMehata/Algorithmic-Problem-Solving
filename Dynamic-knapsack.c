/* 
Knapsack
*/

#include<stdio.h>
#include<string.h>
void printarr(int a[5][6]){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<6;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
int main(){
    int numItem=4,numWeight=5;
    int w[4]={2,1,3,2};
    int v[4]={12,10,20,15};

    //maxWeight is the max weight thief can carry
    int maxWeight = 5;
    int a[numItem+1][maxWeight+1],i,j;
    for(i=0;i<numItem+1;i++){
        for(j=0;j<maxWeight+1;j++){
            a[i][j]=0;
        }
    }
    for(i=1;i<numItem+1;i++){
        for(j=1;j<maxWeight+1;j++){
            if(j-w[i-1] < 0)
                a[i][j]=a[i-1][j];
            else{
                if(a[i-1][j] < (a[i-1][j-w[i-1]] + v[i-1]))
                    a[i][j]=a[i-1][j-w[i-1]]+v[i-1];
                else 
                    a[i][j]=a[i-1][j];
            }
            printarr(a);
        }
    }

    printf("Maximum value that can be filled in a bag of size '5' : %d\n",a[4][5]);
}