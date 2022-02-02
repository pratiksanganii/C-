#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

bool Identity(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1==NULL || root2==NULL){
        return false;
    }
    else{
        bool cnd1=root1->data==root2->data;
        bool cnd2=Identity(root1->left,root2->left);
        bool cnd3=Identity(root1->right,root2->right);
        return cnd1&&cnd2&&cnd3;
    }
}

int main(){
    Node* root1=new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(3);
    Node* root2=new Node(6);
    root2->left=new Node(3);
    root2->right=new Node(10);
    cout<<Identity(root1,root2)<<endl;
    return 0;
}