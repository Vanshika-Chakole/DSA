// factorial using recursion

#include<iostream>
using namespace std;

int fact(int n);

int main(){
 int n ;
 cout<<"Enter the num. :";
 cin>>n;
cout<<"Factorial is:"<<fact(n)<<endl;

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