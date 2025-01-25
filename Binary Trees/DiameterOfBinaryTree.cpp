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
static int i=-1;
node* buildTree(vector<int> &nodes){
    i++;
    if(nodes[i]==-1){
        return NULL;
    }
    node* currNode=new node(nodes[i]);
    currNode->left=buildTree(nodes);
    currNode->right=buildTree(nodes);
    return currNode;
}
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}
int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=height(root->left)+height(root->right)+1;
    int ans= max(op1,max(op2,op3));
    return ans;
}
pair<int, int> diameterHelper(node* root) {
    if (root == nullptr) {
        return {0, 0}; // {height, diameter}
    }

    pair<int, int> left = diameterHelper(root->left);
    pair<int, int> right = diameterHelper(root->right);

    int height = max(left.first, right.first) + 1;
    int diameter = max(left.second, max(right.second, left.first + right.first + 1));

    return {height, diameter};
}
int main() {
    vector<int> nodes={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    node* root=buildTree(nodes);
    cout<<"diameter = "<<diameterHelper(root).second;
    return 0;
}
