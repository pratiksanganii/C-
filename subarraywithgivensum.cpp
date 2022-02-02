// facebook google amazon visa

#include<iostream>
using namespace std;

int sub(int a[],int s, int n){
    int i=0, j=0, st=-1, en=-1, sum=0;

    while(j<n && sum+a[j]<=s){
        sum+= a[j];
        j++;
    }
    if(sum==s){
        cout<<i+1<<" "<<j<<endl;
        return 0;
    }

    while(j<n){
        sum+=a[j];
        while(sum>s){
            sum-=a[i];
            i++;
        }

        if(sum==s){
            st=i+1;
            en=j+1;
            break;
        }
        j++;
    }
    cout<<st<<" "<<en;
}

int main(){
    int n,s;
    int a[n];
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sub(a,s,n);
}