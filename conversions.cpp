#include<bits/stdc++.h>
using namespace std;

int bitoDeci(int n){
    int i=0;
    int x=1;
    while(n>0){
        int y=n%10;
        i+=x*y;
        x*=2;
        n/=10;
    }
    return i;
}

int octatoDeci(int n){
    int i = 0;
    int x = 1;
    while(n>0){
        int y = n%10;
        i += x*y;
        x*=8;
        n/=10;
    }
    return i;
}

int hexadecitoDeci(string n){
    int ans=0;
    int x=1;

    int s = n.size();

    for(int i=s-1;i>=0;i--){
        if(n[i]>='0' && n[i]<='9'){
            ans+= x*(n[i]-'0');
        }
        else if(n[i]>='A' && n[i]<='F'){
            ans+= x*(n[i]-'A'+10);
        }
        x*=16;
    }
    return ans;
}

int decitoBi(int n){
    int x=1;
    int ans=0;
    // 5>10
    while(x<=n){
        x*=2;
    }
    x/=2;                               // x = 4 las=1 n=1 x=2 ans=1 las=0 n=1 x=1 ans=10 las=1 n=0 x=0 ans=101 
    while(x>0){
        int lastdigit = n/x;
        n-=lastdigit*x;
        x/=2;
        ans = ans*10+lastdigit;
    }
    return ans;
}

int decitoOctal(int n){
    int x=1;
    int ans=0;
    while(x<=n){
        x*=8;
    }
    x/=8;
    while(x>0){
        int lastDigit=n/x;
        n-=lastDigit*x;
        x/=8;
        ans=ans*10+lastDigit;
    }
    return ans;
}

string decitoHexadeci(int n){
    int x=1;
    string ans="";
    while(x<=n)
        x*=16;
    x/=16;
    while (x>0)
    {
        int lastdigit = n/x;
        n-=lastdigit*x;
        x/=16;
        if(lastdigit<=9){
            ans = ans + to_string(lastdigit);
        }
        else{
            char c = 'A' + lastdigit - 10;
            ans.push_back(c);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int sumNo[n];
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>sumNo[i];
    }
    for(int i=0;i<n;i++){
        ans = ans + sumNo[i];
    }
    cout<<ans<<endl;
}