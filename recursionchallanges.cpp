#include<iostream>
#include<string>
using namespace std;

string keypad[] = {"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
// combination of keypad phone
void comboofkeys(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string code = keypad[ch-'0'];
    string ros = s.substr(1);
    for(int i=0;i<code.length();i++){
        comboofkeys(ros,ans+code[i]);
    }
}

// check if array is sorted or not
bool sorted(int a[],int n){
    if(n==1){
        return true;
    }
    bool restAr = sorted(a+1,n-1);
    return (a[0]<a[1] && restAr);
}

//decresing order number printing
void dec(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}

//incresing order number printing
void inc(int n){
    if(n==0){
        return;
    }
    inc(n-1);
    cout<<n<<endl;
}

// first occurence index
int firstoccur(int a[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    if(a[i]==key){
        return i;
    }
    return firstoccur(a,n,i+1,key);
}

// last occurance index
int lastoccur(int a[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    int restAr = lastoccur(a,n,i+1,key);
    if(restAr!=-1){
        return restAr;
    }
    if(a[i]==key){
        return i;
    }
    return -1;
}

// reverse string
void reverse(string s){
    if(s.length()==0){
        return;
    }
    string ros = s.substr(1);
    reverse(ros);
    cout<<s[0];
}

// replace pi with 3.14
void replacePi(string s){
    if(s.length()==0){
        return;
    }
    if(s[0]=='p'&&s[1]=='i'){
        cout<<"3.14";
        replacePi(s.substr(2));
    }
    else{
        cout<<s[0];
        replacePi(s.substr(1));
    }
}

void towerofHanoi(int n,char src,char dest,char helper){
    if(n==0){
        return;
    }
    towerofHanoi(n-1,src,helper,dest);
    cout<<"move from "<<src<<" to "<<dest<<endl;
    towerofHanoi(n-1,helper,dest,src);
}

// remove duplocates
string removeDup(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans = removeDup(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    return (ch+ans);
}

// pushing a character at last
string pushtolast(string s){
    if(s.length()==0){
        return "";
    }
    char ch = s[0];
    string ans = pushtolast(s.substr(1));
    if(ch=='x'){
        return (ans+ch);
    }
    return (ch+ans);
}

// print all substrings
void subseq(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    subseq(ros,ans);
    subseq(ros,ans+ch);
}

// print substrings with ascii values
void subseqascii(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    int cod = ch;
    string ros = s.substr(1);
    subseqascii(ros,ans);
    subseqascii(ros,ans+ch);
    subseqascii(ros,ans+to_string(cod));
}

// permutations of given string
void permutation(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        string ros = s.substr(1);
        permutation(ros,ans+ch);
    }
}

// count possible paths to reach destination
int countPath(int s,int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count = 0;
    for(int i=1;i<=6;i++){
        count += countPath(s+i,e);
    }
    return count;
}

// count paths to reach maze end
int countPathMaze(int n,int i,int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    return countPathMaze(n,i+1,j) + countPathMaze(n,i,j+1);
}

//tiling ways
int tilingWays(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return tilingWays(n-1) + tilingWays(n-2);
}

// friends pairing 
int friendsPairing(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }
    return friendsPairing(n-1) + (friendsPairing(n-2) * (n-1));
}

//0-1 knapsack problem
int knapsack(int value[],int wt[],int n,int W){
    if(n==0 || W==0){
        return 0;
    }
    if(wt[n-1]>W){
        return knapsack(value,wt,n-1,W);
    }
    return max(knapsack(value,wt,n-1,W-wt[n-1])+value[n-1],knapsack(value,wt,n-1,W));
}

int main(){
    int a[] = {1,2,2,3,4,8,5,9,10};
    int wt[] = {10,20,30};
    int value[]={100,50,150};
    int W=50;
    cout<<knapsack(value,wt,3,W);
    return 0;
}