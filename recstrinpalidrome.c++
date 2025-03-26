//WA recursion function to check string is palidrome

#include<bits/stdc++.h>
using namespace std;

bool palidrome(const char*str,int left,int right){
    if(left>=right)
    return true;

    if(str[left]!=str[right])
    return false;

    return palidrome(str,left+1,right-1);
}

bool checkpalidrome(const char*str){
    int length = strlen(str);
    return palidrome(str,0,length-1);
}

int main(){
    char str[100];
    cout<<"Enter a string : ";
    cin>>str;
    if(checkpalidrome(str))
    cout<<"The string is plaidrome."<<endl;
    else
    cout<<"The string is not plaidrome."<<endl;
    return 0;
}