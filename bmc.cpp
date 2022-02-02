#include<iostream>
using namespace std;

int powerof2(int n){
    return !(n & (n&(n-1)));
}

bool getBit(int n, int pos){
    return ((n&(1<<pos))!=0);
}

int setBit(int n,int pos){
    return (n | 1<<pos);
}

int freqofones(int n){
    int count=0;
    while(n){
        n=n&(n-1);
        count++;
    }
    return  count;
}

//int setBit(int n, int pos){
//    return ((n&(1<<pos))!=0);
//}

void subsets(int arr[],int n){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int unique(int a[],int n){
    int xorsum = 0;
    for(int i=0;i<n;i++){
        xorsum=xorsum^a[i];
    }
    return xorsum;
}

void twounique(int a[], int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum=xorsum^a[i];
    }        
    int tempxor=xorsum;
    int setbit=0;
    int pos=0;
    while(setbit!=1){
        setbit=xorsum & 1;
        pos++;
        xorsum=xorsum>>1;
    }   
    int newxor=0;
    for(int i=0;i<n;i++){
        if(setBit(a[i],pos-1)){
            newxor=newxor^a[i];
        }
    } 
    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
}

int uniquefromthree(int a[], int n){
    int result=0;
    for(int i=0;i<64;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(getBit(a[j],i)){
                sum++;
            }
        }
        if(sum%3!=0){
            result = setBit(result,i);
        }
    }
    return result;
}

int main(){
    //cout<<powerof2(16);
    //cout<<freqofones(19);
    //int arr[4] = {1,2,3,4};
    //subsets(arr,4);
    int a[]={2,2,4,6,4,6,5,4,2,6};
    cout<<uniquefromthree(a,10);
}