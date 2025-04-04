#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
Node* treeHelper(Node* root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    if(val<root->data){
        root->left=treeHelper(root->left,val);
    } else {
        root->right=treeHelper(root->right,val);
    }
    return root;
}
Node* buildBST(int arr[],int n){
    Node* root=NULL;
    for(int i=0;i<n;i++){
        root=treeHelper(root,arr[i]);
    }
    return root;
}
void printPath(vector<int> path){
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void pathHelper(Node* root,vector<int> &path){
    if(root==NULL){
        return ;
    }
    path.push_back(root->data);
    if(root->left==NULL&&root->right==NULL){//leaf Node
        printPath(path);
        path.pop_back();
        return;
    }
    pathHelper(root->left,path);
    pathHelper(root->right,path);
    path.pop_back();
}
int main() {
    int arr[6]={8,5,3,6,10,11};
    Node* root=buildBST(arr,6);
    vector<int> vec;
    pathHelper(root,vec);
    return 0;
}
