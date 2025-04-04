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

Node* buildBalancedBST(int arr[],int st,int end){
    if(st>end){
        return NULL;
    }
    int mid=st+(end-st)/2;
    Node* curr=new Node(arr[mid]);
    curr->left=buildBalancedBST(arr,st,mid-1);
    curr->right=buildBalancedBST(arr,mid+1,end);
    return curr;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() {
    int arr[8]={1,2,3,4,5,6,7,8};
    Node* root=NULL;
    root=buildBalancedBST(arr,0,7);
    inorder(root);
    return 0;
}
