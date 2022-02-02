#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s1="abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='a' && s1[i]<='z'){
            s1[i]-=32;
        }
    }
    cout<<s1;
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='A' && s1[i]<='Z'){
            s1[i]+=32;
        }
    }
    cout<<s1<<endl;


    string s = "fasksdfu";
    transform(s.begin(),s.end(), s.begin(), ::toupper);
    cout<<s<<endl;
    transform(s.begin(),s.end(), s.begin(), ::tolower);
    cout<<s<<endl;

    string n="5483245";
    sort(n.begin(),n.end(),greater<int>());
    cout<<n<<endl;

    string f="abcacbade";
    int freq[26];
    for(int i=0;i<26;i++){
        freq[i]=0;
    }
    for(int i=0;i<f.size();i++){
        freq[f[i]-'a']++;
    }
    char ans='a';
    int mxfrq=0;
    for(int i=0;i<26;i++){
        if(freq[i]>mxfrq){
            mxfrq=max(mxfrq,freq[i]);
            ans = i+'a';
        }
    }
    cout<<mxfrq<<endl;
    cout<<ans<<endl;
}