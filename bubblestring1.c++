//sorting string for bubble sorting
#include<iostream>
#include<string>

using namespace std;

// void bubblesort(char str[50],int n){
//     int i,j;
void bubblesortstring(string &str){
    int n = str.length();
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if( str[j]>str[j+1]){
                char temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }
}

int main(){
    // char str[][50]={"xyz","abc","mno","kvr"};
    // int n = sizeof(str)/sizeof(str[0]);
    // bubblesort(str[50],n);
     string str;
     cout<<"Enter the string:";
     cin>>str;
     bubblesortstring(str);
        cout<<"Sorted string:"<<str<<endl;
    return 0;
}