#include"bits/stdc++.h"
using namespace std;


class Complex{
    private:
        int real,imag;
    public:
        Complex(int r=0,int i=0){
            real = r;
            imag = i;
        }
    Complex operator + (Complex const &obj){
        Complex res;
        res.imag = imag + obj.imag;
        res.real = real + obj.real;
        return res;
    }
    void display(){
        cout<<real<<" + i"<<imag<<endl;
    }
};

class base{
    public:
    virtual void print(){
        cout<<"print func from base"<<endl;
    }
    virtual void display(){
        cout<<"display func from base"<<endl;
    }
};

class derived: public base{
    public:
    void print(){
        cout<<"print func from derived"<<endl;
    }
    void display(){
        cout<<"display func from derived"<<endl;
    }    
};

int32_t main(){
    base *baseptr;
    derived d;
    baseptr = &d;
    baseptr -> print();
    baseptr -> display();
    return 0;
}