// Time Complexity: O(h) → O(log n) (balanced) to O(n) (skewed).
// Space Complexity: O(h) → O(log n) (balanced) to O(n) (skewed).
#include<iostream>
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
Node* insert(Node* root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    } else {
        root->right=insert(root->right,val);
    }
    return root;
}
Node* buildBST(int arr[],int n){
    Node* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* getInorderSuccessor(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* delNode(Node* root, int val){
    if(root==NULL){
        return NULL;
    }
    if(val<root->data){
        root->left=delNode(root->left,val);
    } else if(val>root->data){
        root->right=delNode(root->right,val);
    } else { //root==val case 1
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        //case 2: 1 child
        if(root->left==NULL||root->right==NULL){
            Node* temp = root->left==NULL?root->right:root->left;
            delete root;
            return temp;
        }
        //case 3: 2 children 
        Node* IS=getInorderSuccessor(root->right);
        root->data=IS->data;
        root->right=delNode(root->right,IS->data);
        // return root;
    }
    return root;
}
int main() {
    int arr[9]={1,3,4,5,6,8,10,11,14};
    Node* root=buildBST(arr,9);
    cout<<"before: ";
    inorder(root);
    delNode(root,8);
    cout<<endl<<"after :";
    inorder(root);
    return 0;
}
