#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left=NULL;
    Node* right=NULL;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// case 1:
void SubNodesAtDistK(Node* root,int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    SubNodesAtDistK(root->left,k-1);
    SubNodesAtDistK(root->right,k-1);
}

// case 2
int AncestorNodesAtDistK(Node* root,Node* target,int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        SubNodesAtDistK(root,k);
        return 0;
    }
    int dl=AncestorNodesAtDistK(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<endl;
        }
        else{
            SubNodesAtDistK(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr=AncestorNodesAtDistK(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<endl;
        }
        else{
            SubNodesAtDistK(root->left,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    AncestorNodesAtDistK(root,root->left,1);
    return 0;
}