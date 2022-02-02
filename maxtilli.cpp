#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int Arr[n];
    for(int i=0;i<n;i++){
        cin>>Arr[i];
    }

    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        mx = max(mx,Arr[i]);
        
        
/*        int j=0;
        for(j;j<=i;j++){
            if(Arr[j]>max){
                max=Arr[j];
            }
        }*/
        cout<<mx<<" ";
    }
    return 0;
}