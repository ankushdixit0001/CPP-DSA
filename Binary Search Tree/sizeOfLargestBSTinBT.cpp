#include<iostream>
#include<vector>
#include<climits>
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
class info{
    public:
    bool isBST;
    int min;
    int max;
    int sz;

    info(bool isBST,int min,int max, int sz){
        this->isBST=isBST;
        this->min=min;
        this->max=max;
        this->sz=sz;
    }
};
static int maxSize;
info* largestBST(Node* root){
    if(root==NULL){
        return new info(true,INT_MAX,INT_MIN,0);
    }
    info* leftInfo=largestBST(root->left);
    info* rightInfo=largestBST(root->right);

    int currMin=min(root->data,min(leftInfo->min,rightInfo->min));
    int currMax=max(root->data,max(leftInfo->max,rightInfo->max));
    int currSz=leftInfo->sz+rightInfo->sz+1;

    if(leftInfo->isBST&&rightInfo->isBST
    && root->data>leftInfo->max
    && root->data<rightInfo->min){
        maxSize=max(maxSize,currSz);
        return new info(true,currMin,currMax,currSz);
    }
    return new info(false,currMin,currMax,currSz);
}
int main() {
    Node* root=new Node(50);
    root->left=new Node(25);
    root->left->left=new Node(12);
    root->left->right=new Node(13);

    root->right=new Node(55);
    root->right->left=new Node(54);
    root->right->right=new Node(60);
    root->right->right->right=new Node(66);


    largestBST(root);
    cout<<maxSize;
    return 0;
}
