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
//same tree nodes and sequence
bool isIdentical(Node* r1,Node* r2){
    if(r1==NULL&&r2==NULL){
        return true;
    }
    if(r1==NULL&&r2!=NULL){
        return false;
    }
    if(r1!=NULL&&r2==NULL){
        return false;
    }
    bool left=isIdentical(r1->left,r2->left);
    bool right=isIdentical(r1->right,r2->right);
    bool value=r1->data==r2->data;
    return left&&right&&value;
}
int main() {
    vector<int> nodes = {1, 2, 3, 4, -1, -1, -1, 5, -1, -1}; 
    vector<int> nodes2 = {1, 2, 3, 4, -1, -1, -1, 5, -1, -1};
    int i1 = 0;  // Initialize i in main and pass it by reference
    int i2 = 0;
    Node* r1 = buildTree(nodes, i1);
    Node* r2 = buildTree(nodes2, i2);
    cout<<isIdentical(r1,r2);
    return 0;
}
