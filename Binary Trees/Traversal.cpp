#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildTree(node* root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }
    root=new node(data);
    cout<<"Enter data for inserting in left of : "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right of : "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
//traverse
void inOrder(node* root){
    //base case
    if(root==NULL){
        return;
    }
    inOrder(root->left); //L
    cout<<root->data<<" "; //N
    inOrder(root->right); //R
}
void preOrder(node* root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" "; //N
    preOrder(root->left); //L
    preOrder(root->right); //R
}
void postOrder(node* root){
    //base case
    if(root==NULL){
        return;
    }
    postOrder(root->left); //L
    postOrder(root->right); //R
    cout<<root->data<<" "; //N
}
int main() {
    node* root=NULL;

    root=buildTree(root);
    cout<<"------- inOrderTravers --------"<<endl;
    inOrder(root);
    cout<<"\n------- preOrderTravers --------"<<endl;
    preOrder(root);
    cout<<"\n------- postOrderTravers --------"<<endl;
    postOrder(root);
    return 0;
}