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
node* buildtree(vector<int> &nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    node* currNode= new node(nodes[idx]);
    currNode->left=buildtree(nodes);
    currNode->right=buildtree(nodes);
    return currNode;
}
int inOrder(node* root, int &cnt){
    //base case
    if(root==NULL){
        return 0;
    }
    inOrder(root->left,cnt); //L
    if(root->left==NULL && root->right==NULL){
        cnt++;
    }
    inOrder(root->right,cnt); //R
    return cnt;
}
int main() {
    vector<int> nodes={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    node* root=buildtree(nodes);
    int cnt=0;
    cout<<inOrder(root,cnt);
    return 0;
}