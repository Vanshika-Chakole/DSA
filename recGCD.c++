// GCD using recursion function

#include<iostream>

using namespace std;

int gcd(int n1, int n2){
    if(n2 == 0){
        return n1;
    }
   return gcd(n2,n1%n2);
}

int main(){
    int n,m;
    cout<<"Enter the numbers:";
    cin>>n;
    cin>>m;
    cout<<"The gcd of both the number is:";
    cout<<gcd(n,m)<<endl;
return 0;    
}