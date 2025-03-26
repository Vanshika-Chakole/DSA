//WA recursion function to reverse the null terminated string

#include<iostream>
using namespace std;

void reverseString(char*str, int left, int right){
    if(left >= right){
        return;
    }
    swap(str[left],str[right]);

    reverseString(str,left+1,right-1);
}

void reverse(char*str){
    int len = 0;
    while(str[len]!='\0')
    len++;

    if(len>0)
    reverseString(str,0,len-1);
}

int main(){
    char str[]="Vanshika";
    cout<<"Original string:"<<str<<endl;

    reverse(str);

    cout<<"Revsere String:"<<str<<endl;
}