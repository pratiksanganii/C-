#include"bits/stdc++.h"
using namespace std;

class ApnaCollege{
    public:
    void fun(){
        cout<<"no argue"<<endl;
    }
    void fun(int c){
        cout<<"int argue"<<endl;
    }
    void fun(double c){
        cout<<"double argue"<<endl;
    }
};

int main(){
    ApnaCollege Obj;
    Obj.fun();
    Obj.fun(4);
    Obj.fun(6.2);
}