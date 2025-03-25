#include<stdio.h>

int fact(int n);

int main(){
 int n ;
 printf("Enetr the num. :");
 scanf("%d",&n);
 printf("Factorial of %d is : %d",n,fact(n));
 return 0;
}

int fact(int n){
    if(n == 0 || n == 1){
        if(n == 0){
            return 0;
        }
        if(n == 1) {
            return 1;
        }
    }
    int factNm1 = fact(n-1);
    int factN = n*factNm1;
    return factN;
}