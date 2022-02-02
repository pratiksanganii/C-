#include<iostream>
using namespace std;

void sum(int Arr[], int n){
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum += Arr[j];
            cout<<sum<<endl;
        }
    }
}

int main(){
    int n;
    int Arr[n];
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>Arr[i];
    }

    sum(Arr,n);
    
    return 0;
}