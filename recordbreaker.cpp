// Problem from Google Kickstart

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int Arr[n+1];
    Arr[n]=-1;
    for(int i=0;i<n;i++){
        cin>>Arr[i];
    }

    if(n==1){
        cout<<"1"<<endl;
        return 0;
    }

    int ans=0;
    int mx=-1;

    for(int i=0;i<n;i++){
        if(Arr[i]>mx && Arr[i]>Arr[i+1]){
            ans++;
        }
        mx=max(mx,Arr[i]);
    }
    cout<<ans<<endl;
}