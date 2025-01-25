#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* buildTree(const vector<int>& nodes, int& i) {
    if (i >= nodes.size() || nodes[i] == -1) {
        i++;
        return nullptr;
    }
    Node* newNode = new Node(nodes[i++]);
    newNode->left = buildTree(nodes, i);
    newNode->right = buildTree(nodes, i);
    return newNode;
}

pair<bool, int> isSumTree(Node* root) {
    if (root == nullptr) {
        return {true, 0};
    }
    if (root->left == nullptr && root->right == nullptr) {
        return {true, root->data};
    }

    pair<bool, int> leftAns = isSumTree(root->left);
    pair<bool, int> rightAns = isSumTree(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;
    bool cond = root->data == leftAns.second + rightAns.second;

    pair<bool, int> ans;
    if (left && right && cond) {
        ans.first = true;
        ans.second = root->data + leftAns.second + rightAns.second;
    } else {
        ans.first = false;
    }
    return ans;
}

int main() {
    vector<int> nodes = {4, 2, -1, -1, 2, -1, -1}; 
    int i = 0;  // Initialize i in main and pass it by reference
    Node* root = buildTree(nodes, i);
    cout << (isSumTree(root).first ? "True" : "False") << endl;
    return 0;
}