// Question from Google Kickstart

#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    int n;
    cin>>n;
    int Arr[n];
    for(int i=0;i<n;i++){
        cin>>Arr[i];
    }
for(int i=1;i<=T;i++){
    int ans=2;
    int j=2;
    int pd=Arr[1]-Arr[0];
    int cd=2;
    while(j<n){
        if(pd==Arr[j]-Arr[j-1]){
            cd++;
        }
        else if(pd!=Arr[j]-Arr[j-1]){
            pd=Arr[j]-Arr[j-1];
            cd=2;
        }
        ans = max(ans,cd);
        j++;
    }
    cout<<i<<":";
    cout<<ans<<endl;
}
    return 0;
}