#include<iostream>
using namespace std;

// sum till n
int sum(int n){
    if(n==0){
        return 0;
    }
    int prevsum = sum(n-1);
    return n + prevsum;
}

// n to the power p
int ntpp(int n,int p){
    if(p==0){
        return 1;
    }
    int prevpower = ntpp(n,p-1);
    return n*prevpower;
}

// factorial of n
int fact(int n){
    if(n==1){
        return 1;
    }
    int prevFact = fact(n-1);
    return n*prevFact;
}

// Fibbonachi series
int fib(int n){
    if(n==0 || n==1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}

int main(){
    cout<<fib(7);
}