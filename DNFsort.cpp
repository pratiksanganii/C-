#include<iostream>
using namespace std;

void dnfsort(int arr[],int n){
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;                                                        
        }
        if(arr[mid]==1){
            mid++;
        }
        if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main(){
    int arr[]={1,0,2,1,0,1,2,1,2};
    dnfsort(arr,9);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}