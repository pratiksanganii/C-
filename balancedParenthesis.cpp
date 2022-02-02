#include<bits/stdc++.h>
using namespace std;

bool balancedParantheses(string s){
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.top()=='('){
                st.pop();
            }
            else{
                return 0;
            }
        }
        else if(s[i]==']'){
            if(st.top()=='['){
                st.pop();
            }
            else{
                return 0;
            }
        }
        else if(s[i]=='}'){
            if(st.top()=='{'){
                st.pop();
            }
            else{
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    string s="{[()}]";
    cout<<balancedParantheses(s)<<endl;
    return 0;
}