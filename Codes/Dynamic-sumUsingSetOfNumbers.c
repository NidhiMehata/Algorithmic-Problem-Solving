/* 
Ways to get a sum using given set of numbers
*/

#include<stdio.h>
#include<string.h>
int main(){
    int num[]={3,5,10};
    int sum=15,i,j,n;
    int arr[sum+1];
    //To set the all array elements to zero
    memset(arr,0,sizeof(arr));
    arr[0]=1;
    for(n=0;n<3;n++){
        for(i=num[n],j=0;i<=sum;i++,j++){
            arr[i]=arr[i]+arr[j];    
        }
    }
    for(i=0;i<=sum;i++){      
        printf("Sum : %d\t Number of ways : %d\n",i,arr[i]);
    }
}
