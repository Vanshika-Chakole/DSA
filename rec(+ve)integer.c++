//WA recursive function to count the digit of (+ve) integer(sum of digits)

#include<iostream>

using namespace std;
int countDigit(int num){
    if(num==0)
    return 0;
    return 1+countDigit(num/10);
}

int sumofDigit(int num){
    if(num==0)
    return 0;
    return(num%10)+sumofDigit(num/10);
}

int main(){
    int num;
    cout<<"Enter a positive integer: "<<"\n";
    cin>>num;

    if(num<=0){
        cout<<"Please enter a (+ve) integer:"<<endl;
        return 1;
    }
    cout<<"Number of digits is :"<<countDigit(num)<<"\n";
    cout<<"Sum of the integer of is :"<<sumofDigit(num)<<"\n";

    return 0;
}