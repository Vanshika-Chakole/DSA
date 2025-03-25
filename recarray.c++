// WA recursive function to search the element in array

#include<iostream>
using namespace std;
int linearSearch(int arr[],int size,int key,int index){
    if(index>=size){
        return -1;
    }
    if(arr[index]==key)
        return index;
    
    return linearSearch(arr,size,key,index+1);
}

int main(){
    int arr[]={10,20,30,40,50};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 30;
    int result = linearSearch(arr,size,key,0);
    if(result!=1)
    cout<<"Element"<<" "<<key<<" "<<"found at index:"<<result<<endl;
    
    else{
      cout<<"Element"<<key<<"not found"<<endl;
    }
    return 0;
}