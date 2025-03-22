#include<stdio.h>

int gcd(int num1, int num2);

int main(){
    int num1, num2;
    printf("Enter the 2 number :");
    scanf("%d%d",&num1,&num2);
    printf("Greatset common divisor in %d and %d is: %d",num1, num2,gcd(num1,num2));
}

int gcd(int num1, int num2 ){
      if(num1 == 0){
        return num2;
      }
      else if(num2 == 0){
        return num1;
      }
      else{
        gcd(num2,num1%num2);
      }
}