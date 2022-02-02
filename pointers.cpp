#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
/*    int a=10;
    int *aptr = &a;
    cout<<*aptr;
    *aptr=20;
    cout<<a;
*/
/*    int a[] ={10,20,30};
    int *ptr = a;
    for(int i=0;i<3;i++){
        //cout<<*ptr<<endl;
        //*ptr++;
        cout<<*(a+i)<<endl;         
    }
*/
/*    int a=2,b=4;
    swap(&a,&b);
    cout<<a<<b;
*/
    int arr[] = {10,20,30};
    for(int i=0;i<3;i++){
        cout<<*(arr+i)<<endl;
    }
}