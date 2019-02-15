/* 
Case Conversion using bit manipulation 
    To convert from upper to lower : 
        - upper or with 32
    To convert from lower to upper :
        - lower and with not of 32
*/
#include<stdio.h>
int main(){
    char upper='A';
    printf("To Lower : %c\n", upper | 32);

    char lower='a';
    printf("To Upper : %c", lower & ~32 );
}
