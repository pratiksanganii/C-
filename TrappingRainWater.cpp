#include<bits/stdc++.h>
using namespace std;

int rainwater(vector<int>a){
    stack<int>st;
    int n=a.size(),ans=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<a[i]){
            int cur=st.top();
            cout<<st.top()<<endl;  
            st.pop();
            if(st.empty()){                
                break;                    
            }
            cout<<st.top()<<endl;
            int diff=i-st.top()-1;
            ans+=(min(a[st.top()],a[i])-a[cur])*diff;
        }
        st.push(i);
    }    
    return ans;
}

int32_t main(){
    vector<int>a={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rainwater(a)<<endl;
}