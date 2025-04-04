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
// bool isValidBST(Node* root){
//     if(!root){
//         return true;
//     }
//     if(root->left->data<root->data&&root->data<root->right->data){
//         return true;
//     }else{
//         return false;
//     }
//     bool left=isValidBST(root->left);
//     bool right=isValidBST(root->right);
//     return left&&right;
// }
bool validateHelper(Node* root,Node* min,Node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL&&root->data<min->data){
        return false;
    }
    if(max!=NULL&&root->data>max->data){
        return false;
    }
    return validateHelper(root->left,min,root)&&validateHelper(root->right,root,max);
}
bool validateBST(Node* root){
    return validateHelper(root,NULL,NULL);
}
int main() {
    int arr[6]={8,5,3,6,10,11};
    Node* root=buildBST(arr,6);
    cout<<validateBST(root);
    return 0;
}
