#include<iostream>
#include<vector>
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
static int idx=-1;
node* buildTree(vector<int> &nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    node* currNode= new node(nodes[idx]);
    currNode->left=buildTree(nodes);
    currNode->right=buildTree(nodes);
    return currNode;
}
int sumOfNode(node* root){
    if(root==NULL){
        return 0;
    }
    int leftSum=sumOfNode(root->left);
    int rightSum=sumOfNode(root->right);
    return leftSum+rightSum+root->data;
}
int main() {
    vector<int> nodes={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    node* root=buildTree(nodes);
    cout<<"Sum Of Nodes = "<<sumOfNode(root)<<endl;
    return 0;
}
