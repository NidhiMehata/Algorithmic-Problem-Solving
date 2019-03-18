/* 
    Assign jobs in the most optimal way
*/
#include<stdio.h>
#include<math.h>
#include<limits.h>
#define min(a,b) a<b?a:b
int countSetBits(int n){
    int count = 0,c;
    while(n){
        c = n & 1;
        if(c)
            count++;
        n = n>>1;
    }
    return count;
}
int assign(int c[3][3],int n){
    int set_size = pow(2,n);
    int d[set_size],i,j,mask,x;

    
    for(i = 0;i<set_size;i++)
        d[i] = INT_MAX;
    d[0] = 0;

    for(mask = 0;mask<set_size;mask++){
        x = countSetBits(mask);
        printf("%d\n",mask);
        for(j = 0;j < n;j++){
            if((mask & (1<<j)) == 0){ //checking if the jth person has been assigned a job in the mask
                d[mask | (1<<j)] = min(d[mask|(1<<j)],d[mask]+c[x][j]);
            }
            for(i = 0;i < set_size;i++)
            printf("%d\t",d[i]);
        printf("\n");
        }
        for(i = 0;i < set_size;i++)
            printf("%d\t",d[i]);
        printf("\n");
    }
}


int main(){
    //rows : person ; col : job
    int c[][3]={{8,2,5},{3,2,7},{4,1,2}};
    assign(c,3);

}