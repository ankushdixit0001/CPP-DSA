// Overall Complexity:

// Time Complexity:

// Building the initial BST: O(n^2) (worst case) or O(n log n) (best case).
// Extracting nodes using getNode: O(n).
// Sorting the nodes: O(n log n).
// Building the balanced BST: O(n).
// Inorder traversal: O(n).
// Worst Case: O(n^2) (due to the unbalanced BST creation).
// Best Case: O(n log n).

// Space Complexity:

// Building the initial BST: O(n) (recursion stack for insert in the worst case).
// Extracting nodes using getNode: O(n) (for the nodes vector).
// Sorting the nodes: O(n) (temporary storage for sorting).
// Building the balanced BST: O(log n) (recursion stack for buildBalancedBST).
// Inorder traversal: O(log n) (recursion stack for inorder).
// Overall Space Complexity: O(n).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

Node* buildBalancedBST(vector<int> arr, int st, int end) {
    if (st > end) {
        return NULL;
    }
    int mid = st + (end - st) / 2;
    Node* curr = new Node(arr[mid]);
    curr->left = buildBalancedBST(arr, st, mid - 1);
    curr->right = buildBalancedBST(arr, mid + 1, end);
    return curr;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void getNode(vector<int>& nodes, Node* root) {
    if (root == NULL) {
        return;
    }
    getNode(nodes, root->left);
    nodes.push_back(root->data);
    getNode(nodes, root->right);
}

int main() {
    int arr[8] = {1, 4, 5, 3, 7, 9, 2, 8};
    Node* root = buildBST(arr, 8);

    // Get the nodes of the BST in sorted order
    vector<int> nodes;
    getNode(nodes, root);

    // Sort the nodes to prepare for building a balanced BST
    sort(nodes.begin(), nodes.end());

    // Build a balanced BST from the sorted nodes
    root = buildBalancedBST(nodes, 0, nodes.size() - 1);

    // Print the inorder traversal of the balanced BST
    cout << "Inorder traversal of the balanced BST: ";
    inorder(root);
    cout << endl;

    return 0;
}