#include<stdio.h>
void findSum(int a[],int n,int sum){
    int dp[n+1][sum+1];
    int i,j;
    for(i=0;i<n+1;i++){
        for(j=0;j<sum+1;j++){
            if(i==0 && j==0)
                dp[i][j] = 1;
            else if(j==0)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }

    for(i=1;i<n+1;i++){
        for(j=1;j<sum+1;j++){
            if(dp[i-1][j] == 1)
                dp[i][j]=1;
            else if(a[i-1] > j)
                continue;
            else if(dp[i-1][j-a[i-1]] == 1){
                dp[i][j] = 1;
            }
        }
    }

    for(i=0 ; i<=n ;i++){
        for(j=0 ; j<=sum ;j++){
            printf("%d\t",dp[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int a[]={7,2,3,5,7},n=5,sum=9;
    findSum(a,n,9);
}