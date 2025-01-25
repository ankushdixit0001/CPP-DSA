#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* buildTree(Node* root){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in the left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in the right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
int leftSum(Node* root,bool isLeft){
    if(root==NULL){
        return 0;
    }
    if(!root->left&&!root->right&&isLeft){
        return root->data;
    }
    return leftSum(root->left,true)+leftSum(root->right,false);
}
int main() {
    Node* root=NULL;
    root=buildTree(root);
    cout<<leftSum(root,false);
    return 0;
}
