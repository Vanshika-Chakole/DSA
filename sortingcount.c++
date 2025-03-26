//WAP to count the swaps required to sort an array using insertion sort

#include<iostream>
using namespace std;

int insertionSwap(int arr[],int n){
    int swapCount = 0;
     for(int i=0;i<n;i++){
        int a = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>a){
            arr[j+1]= arr[j];
            j--;
            swapCount++;
        }
        arr[j+1]=a;
     }
     return swapCount;
}

int main(){
    int arr[]={2,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int swapCount = insertionSwap(arr,n);
    cout<<"Array: "<<arr[0]<<","<<arr[1]<<","<<arr[2]<<endl;
    cout<<"Number of swaps required to sort the given array: "<<swapCount<<endl;
    return 0;
}