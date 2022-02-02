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

bool checkBST(Node* root,Node* min,Node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    bool leftValid = checkBST(root->left,min,root);
    bool rightValid = checkBST(root->right,root,max);
    return leftValid && rightValid;
}

int main(){
    Node* root=new Node(3);
    root->left=new Node(2);
    root->left->left=new Node(1);
    root->right=new Node(7);
    root->right->left=new Node(5);
    root->right->right=new Node(8);
    cout<<checkBST(root,NULL,NULL)<<endl;
    return 0;
}