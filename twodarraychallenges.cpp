#include<iostream>
using namespace std;

int main(){

    // transpose of matrix 
    
/*    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    
    for(int i=0;i<3;i++){
        for(int j=i;j<3;j++){
            int temp = a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
           cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

*/
    // matrix multiplication

/*    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int m1[n1][n2];
    int m2[n2][n3];
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            cin>>m1[i][j];
        }
    }
    
    for(int i=0;i<n2;i++){
        for(int j=0;j<n3;j++){
            cin>>m2[i][j];
        }
    }

    int ans[n1][n3];
    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            ans[i][j]=0;
        }
    }

    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            for(int k=0;k<n2;k++){
                ans[i][j]+= m1[i][k]*m2[k][j];
            }
        }
    }

    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
*/

    int n,m,gv;
    cin>>n>>m>>gv;

    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    int r=0, c=m-1;
    bool found=false;
    while(r<n && c>=0){
        if(a[r][c]==gv){
            found=true;
        }
        if(a[r][c]>gv){
            c--;
        }
        else{
            r++;
        }
    }
    if(found){
        cout<<"element found";
    }
    else{
        cout<<"element does not exist";
    }
}