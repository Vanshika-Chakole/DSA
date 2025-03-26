//WAP to sort array of string using selection sort

#include<bits/stdc++.h>
using namespace std;

void selection(string arr[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            string temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// void print(string arr[],int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//        // cin>>arr[i];
//     }
//     cout<<endl;
// }

int main(){
    string arr[5];
    int i;
    
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter the no. of element: ";
    cin>>n;
    
    for(i=0;i<n;i++) 
    cin>>arr[i];
    
    cout<<"Original Array: "<<endl;
    for(i=0;i<n;i++)
    cout<<arr[i]<<"\n";

    selection(arr,n);

    cout<<"Sorted string: "<<endl;
    for(i=0;i<n;i++)
    cout<<arr[i]<<"\n";
    return 0;
}