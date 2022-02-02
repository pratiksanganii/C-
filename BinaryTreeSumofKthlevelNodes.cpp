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

int sumAtK(Node* root,int k){
    if(root==NULL){
        return -1;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    int lvl=0;
    int sum=0;

    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            if(lvl==k){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            lvl++;
        }
    }
    return sum;
}

int32_t main(){
    Node *root=new Node(5);
    root->left=new Node(6);
    root->left->right=new Node(1);
    root->left->right->left=new Node(2);
    root->left->right->left->left=new Node(3);
    root->left->right->left->right=new Node(5);
    root->left->left=new Node(9);
    root->right=new Node(3);
    root->right->right=new Node(1);
    root->right->left=new Node(2);
    root->right->left->right=new Node(6);
    root->right->left->right->right=new Node(7);

    Node *roon=new Node(1);
    roon->left=new Node(2);
    roon->right=new Node(3);
    roon->left->left=new Node(4);
    roon->left->right=new Node(5);
    roon->right->left=new Node(6);
    roon->right->right=new Node(7);

    cout<<sumAtK(roon,2)<<endl;
    cout<<sumAtK(root,3)<<endl;
}