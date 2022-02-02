#include<iostream>
#include<climits>
using namespace std;

// kadane's algorithm
int kadane(int a[],int n){
    int curSum = 0;
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        curSum+=a[i];
        if(curSum<0){
            curSum=0;
        }
        maxSum=max(maxSum,curSum);
    }

    return maxSum;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int wrapsum;
    int nonwrapsum;

    nonwrapsum = kadane(a,n);
    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum+=a[i];
        a[i]=-a[i];
    }

    wrapsum = totalsum + kadane(a,n);
    cout<<max(wrapsum,nonwrapsum)<<endl;
}