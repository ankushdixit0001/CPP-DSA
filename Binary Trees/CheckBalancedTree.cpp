#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* buildTree(vector<int> &nodes, int &i) {
    if (i >= nodes.size() || nodes[i] == -1) {
        i++;
        return NULL;
    }
    Node* currNode = new Node(nodes[i++]);
    currNode->left = buildTree(nodes, i);
    currNode->right = buildTree(nodes, i);
    return currNode;
}
//height of left subtree and right subtree no more than 1 fo are node.

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}
pair<bool,int> isBalancedFast(Node* root){//O(N)
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    pair<int,int> left=isBalancedFast(root->left);
    pair<int,int> right=isBalancedFast(root->right);
    bool leftAns=left.first;
    bool rightAns=right.first;
    bool diff=abs(left.second-right.second)<=1;
    pair<bool,int> ans;
    ans.second=max(left.second,right.second)+1;
    if(leftAns&&rightAns&&diff){
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    return ans;
}
bool isBalanced(Node* root) {//O(N*N)
    // base case
    if (root == NULL) {
        return true;
    }
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    return left && right && diff;
}

int main() {
    vector<int> nodes = {1, 2, 3, 4, -1, -1, -1, 5, -1, -1}; //ub 1, 2, 3, 4, -1, -1, -1, 5, -1, -1   b1, 10, 5, -1, -1, -1, 39, -1, -1
    int i = 0;  // Initialize i in main and pass it by reference
    Node* root = buildTree(nodes, i);
    bool Ans = isBalancedFast(root).first;
    cout << Ans;
    return 0;
}
