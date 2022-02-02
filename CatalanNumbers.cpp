#include<iostream>
#include<vector>
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

// Possibe BSTs
vector<Node*> constructTrees(int start,int end){
    vector<Node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++){
        vector<Node*> leftSubtrees=constructTrees(start,i-1);
        vector<Node*> rightSubtrees=constructTrees(i+1,end);

        for(int j=0;j<leftSubtrees.size();j++){
            Node* left=leftSubtrees[j];
            for(int k=0;k<rightSubtrees.size();k++){
                Node* right=rightSubtrees[k];
                Node* node=new Node(i);
                node->left=left;
                node->right=right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int catalan(int n){
    if(n<=1){
        return 1;
    }
    int res=0;
    for(int i=0;i<=(n-1);i++){
        res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}

// Applications of Catalan Numbers 

// 1 Possible BSTs
// 2 Parenthesis/bracket Combinations
// 3 Possible forests
// 4 Ways of triangulations
// 5 Possible paths in matrix
// 6 Dividing a circle using n chords
// 7 Dyck words of given length
//     & much more

int main(){
    // for(int i=0;i<10;i++){
    //     cout<<catalan(i)<<endl;
    // }
    vector<Node*> totalTrees=constructTrees(1,3);
    for(int i=0;i<totalTrees.size();i++){
        cout<<(i+1)<<" : ";
        preorderPrint(totalTrees[i]);
        cout<<endl;
    }
    return 0;
}