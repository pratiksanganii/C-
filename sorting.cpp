#include<iostream>
using namespace std;
/*
void selectionSort(int Arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(Arr[j]<Arr[i]){
                int temp=Arr[j];
                Arr[j]=Arr[i];
                Arr[i]=temp;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<Arr[i]<<" ";    
    }
}

void bubbleSort(int Arr[],int n){
    int counter=1;
    while(counter<n-1){
        for(int i=0;i<n-counter;i++){
            if(Arr[i]>Arr[i+1]){
                int temp = Arr[i];
                Arr[i]=Arr[i+1];
                Arr[i+1]=temp;
            }
        }
        counter++;
    }
    for(int i=0;i<n;i++){
        cout<<Arr[i]<<" ";    
    }
}

void insertionSort(int Arr[],int n){
    for(int i=1; i<n;i++){
        int current = Arr[i];
        int j = i-1;
        while(Arr[j]>current && j>=0){
            Arr[j+1]=Arr[j];
            j--;
        }
        Arr[j+1]=current;
    }
    for(int i=0;i<n;i++){
        cout<<Arr[i]<<" ";    
    }
}
*/
int main(){
    int T;
    int n;
    cin>>T;
    cout<<endl;
    cout<<"Enter the size of Array : ";
    cin>>n;
    cout<<endl;
    int Arr[n];
    for(int i=0;i<n;i++){
        cin>>Arr[i];    
    }

    int counter=1;
    while(counter<n-1){
        for(int i=0;i<n-counter;i++){
            if(Arr[i]>Arr[i+1]){
                int temp=Arr[i+1];
                Arr[i+1]=Arr[i];
                Arr[i]=temp;
            }
        }
        counter++;
    }  
    
    int mindif=(Arr[1]-Arr[0]);
    for(int i=0;i<n-1;i++){
        int dif=Arr[i]-Arr[i+1];
        if(mindif>abs(dif)){
            mindif=abs(dif);
        }
    }   

    cout<<mindif; 
}