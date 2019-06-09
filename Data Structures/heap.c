#include<stdio.h>

void bottom_up_heap(int h[],int n){
    int i, k, v, heap;
    for(i = n/2 ; i >= 1; i--){
        k = i;
        v = h[i];
        heap = 0;
        while(!heap && 2*k <= n){
            
            int j = 2*k;
            //Check if it has two children
            if( j < n){
                if( h[j+1] > h[j] )
                    j = j + 1;
            }
            //Check if heap is true
            if( v > h[j] )
                heap = 1;
            else{
            //If not swap k and j
                h[k] = h[j];
                k = j;
            }        
        }
        h[k] = v;
    }
   
}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heap_sort(int h[],int n){
    int i;
    for(i = n-1; i >=1; i--){
        bottom_up_heap(h,i);
        swap(&h[1],&h[i]);
    }
}

int main(){
    int h[]={0,3,2,7,9,11,5,6},i;
    int n = 7;
    heap_sort(h,n);
    for(i = 1; i<n; i++)
        printf("%d\t",h[i]);
}