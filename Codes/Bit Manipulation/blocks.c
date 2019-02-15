#include<stdio.h>

int main(){
    int n=2,result;
    
    //1 : If power of 2 result is 0
    result = n & (n-1);
    printf("Result : %d\n",result);

    //2 : Prints the number of set bits
    result = 0;
    while(n){
        result = result + 1 ;
        n = n & (n-1);
    }
    printf("Result : %d\n",result);

    //3 : Even or Odd
    n=2;
    result = n & 1;
    printf("Result : %d\n",result);

    //4 : 2's Complement
    result = ~n + 1; 
    printf("Result : %d\n",result);

    //5. Check if multiple of 8
    n = 16 ;
    result = (n >> 3 ) <<3;
    if(result==n)
        printf("Guess what,Im a multiple of 8\n");

}