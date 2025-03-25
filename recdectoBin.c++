//WA recursion function to convert the decimal into binary

#include<iostream>
using namespace std;

void dectoBin(int n){
    if(n==0){
        return;
    }
    dectoBin(n/2);
    cout<<(n%2);
}

int main(){
    int n;
    cout<<"Enter a decimal number: ";
    cin>>n;
    if(n == 0)
        cout<<"Binary: ";
        dectoBin(n);
        cout<<endl;
    return 0;
}