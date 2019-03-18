/* Return the number of subsets whose sum is greater than or equal to the given value */
#include<stdio.h>
#include<math.h>

int subsetNum(int set[],int set_size,int value){
    int count=0,i,j,sum=0;
    int subset_size=pow(2,set_size);

    for(i=0;i < subset_size ;i++){
        sum=0;
        for(j=0;j<set_size;j++){
            if (i & (1<<j)){
                sum+=set[j];
                printf("%d ",set[j]);
            }
        }
        if(sum >= value){
            count++;
        }
        printf("\n");
    }
    return count;
}

int main(){
    int a[]={1,2,3};
    int n=3,v=5;
    int c = subsetNum(a,n,v);
    printf("Number of elements greater than or equal to %d : %d ",v,c);
}