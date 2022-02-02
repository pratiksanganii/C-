#include<bits/stdc++.h>
#include<stack>
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

void ZigZagTraversal(Node* root){
    if(root==NULL){
        return;
    }
    stack<Node*>currLvl,nxtLvl;
    bool LeftToRight=true;
    currLvl.push(root);
    while(!currLvl.empty()){
        Node* temp=currLvl.top();
        currLvl.pop();

        if(temp){
            cout<<temp->data<<" ";

        if(LeftToRight){
            if(temp->left){
                nxtLvl.push(temp->left);
            }
            if(temp->right){
                nxtLvl.push(temp->right);
            }   
        }
        else{
            if(temp->right){
                nxtLvl.push(temp->right);
            }
            if(temp->left){
                nxtLvl.push(temp->left);
            }
        }
    }
        if(currLvl.empty()){
            LeftToRight=!LeftToRight;
            swap(currLvl,nxtLvl);
        }
    }
}

int main(){
    Node* root=new Node(12);
    root->left=new Node(9);
    root->right=new Node(15);
    root->left->left=new Node(5);
    root->left->right=new Node(10);
    ZigZagTraversal(root);
    return 0;
}