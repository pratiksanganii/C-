#include<iostream>
using namespace std;

int linSearch(int Arr[], int n, int k){
    for(int i=0;i<n;i++){
        if(Arr[i]==k){
            return i;
        }
    }
    return -1;
}

int binSearch(int Arr[],int n, int k){
    int s=0;
    int e=n;
    while(s<=e){
        int mid=(s+e)/2;
        if(Arr[mid]==k){
            return mid;
        }
        else if(Arr[mid]>k){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}

int main(){
    int n;
    int Arr[n];
    cout<<"Enter the size of Array : "<<endl;
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>Arr[i];
    }
    cout<<"Enter the num you want to search in array : ";
    int k;
    cin>>k;
    cout<<binSearch(Arr,n,k);
    return 0;
}