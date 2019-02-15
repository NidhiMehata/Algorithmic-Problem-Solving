/* Generate Powerset of the given set using bit manipulation */
#include<stdio.h>
#include<math.h>
int main(){
    char set[] = {'a','b','c'};
    int setSize = 3,i,j;
    int powersetSize = pow(2,setSize);
    for(i = 0;i < powersetSize; i++){
        for(j = 0; j< setSize; j++){
            if( i & (1<<j) )
                printf("%c",set[j]);
        }
        printf("\n");
    }
}