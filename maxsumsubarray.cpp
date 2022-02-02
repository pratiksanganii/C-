#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // bruteforce Approach
    int maxAns=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int ans=0;
            for(int k=i;k<=j;k++){
                ans+=a[k];
            }
            maxAns = max(maxAns,ans);
        }
    }
    cout<<maxAns;

    // Optimal Approach
    int currsum[n+1];
    currsum[0] = 0;
    for(int i=1;i<=n;i++){
        currsum[i]=currsum[i-1]+a[i-1];
    }
    int maxSum = INT_MIN;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=0;j<i;j++){
            sum = currsum[i]-currsum[j];
            maxSum=max(sum,maxSum);
        }
    }
    cout<<maxSum;

    // kadane algorithm
    int curSm = 0;
    int mxSm=INT_MIN;
    for(int i=0;i<n;i++){
        curSm+=a[i];
        if(curSm<0){
            curSm=0;
        }
        mxSm=max(mxSm,curSm);
    }
    cout<<mxSm;
    return 0;
}