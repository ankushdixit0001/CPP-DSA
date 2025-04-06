/* 
### **Time Complexity (TC)**

#### 1. **Sorting the Vectors**:
   - Sorting `vec1` and `vec2` takes:
     - `O(n log n)` for `vec1` (where `n` is the size of `vec1`).
     - `O(m log m)` for `vec2` (where `m` is the size of `vec2`).

#### 2. **Building Balanced BSTs**:
   - Constructing balanced BSTs from sorted vectors takes:
     - `O(n)` for `vec1`.
     - `O(m)` for `vec2`.

#### 3. **Inorder Traversal**:
   - Performing inorder traversal on the two BSTs takes:
     - `O(n)` for `root1`.
     - `O(m)` for `root2`.

#### 4. **Merging the Vectors**:
   - Merging the two sorted vectors takes:
     - `O(n + m)`.

#### 5. **Building the Merged Balanced BST**:
   - Constructing the merged balanced BST takes:
     - `O(n + m)`.

---

### **Overall Time Complexity**:
The overall time complexity is:
```
O(n log n + m log m) + O(n + m) + O(n + m)
= O(n log n + m log m)
```
The sorting step dominates the time complexity.

---

### **Space Complexity (SC)**

#### 1. **Sorting**:
   - Sorting the vectors is done in-place, so no extra space is required.

#### 2. **Inorder Traversal**:
   - The `inorderTraversal` function uses:
     - `O(n)` space for storing the elements of `root1` in `nodes1`.
     - `O(m)` space for storing the elements of `root2` in `nodes2`.

#### 3. **Merging**:
   - The `mergeSortedVectors` function uses:
     - `O(n + m)` space for the merged vector.

#### 4. **Building the Balanced BST**:
   - The recursion stack for `buildBalancedBST` takes:
     - `O(log(n + m))` space.

---

### **Overall Space Complexity**:
The overall space complexity is:
```
O(n + m) (for storing the merged vector)
```
The recursion stack (`O(log(n + m))`) is negligible compared to the space used for the merged vector.

---

### **Summary**

- **Time Complexity**: `O(n log n + m log m)`
- **Space Complexity**: `O(n + m)`

*/

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

// Function to build a balanced BST from a sorted vector
Node* buildBalancedBST(const vector<int>& sortedValues, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    Node* root = new Node(sortedValues[mid]);
    root->left = buildBalancedBST(sortedValues, start, mid - 1);
    root->right = buildBalancedBST(sortedValues, mid + 1, end);
    return root;
}

// Function to perform an inorder traversal and store the result in a vector
void inorderTraversal(Node* root, vector<int>& result) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left, result);
    result.push_back(root->data);
    inorderTraversal(root->right, result);
}

// Function to merge two sorted vectors into one sorted vector
vector<int> mergeSortedVectors(const vector<int>& vec1, const vector<int>& vec2) {
    vector<int> merged;
    int i = 0, j = 0;

    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] < vec2[j]) {
            merged.push_back(vec1[i++]);
        } else {
            merged.push_back(vec2[j++]);
        }
    }
    while (i < vec1.size()) {
        merged.push_back(vec1[i++]);
    }
    while (j < vec2.size()) {
        merged.push_back(vec2[j++]);
    }

    return merged;
}

// Function to merge two BSTs into a single balanced BST
Node* mergeBSTs(Node* root1, Node* root2) {
    vector<int> nodes1, nodes2;

    // Get inorder traversal of both BSTs
    inorderTraversal(root1, nodes1);
    inorderTraversal(root2, nodes2);

    // Merge the two sorted vectors
    vector<int> merged = mergeSortedVectors(nodes1, nodes2);

    // Build a balanced BST from the merged sorted vector
    return buildBalancedBST(merged, 0, merged.size() - 1);
}

// Function to print the inorder traversal of a BST
void printInorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    // Input vectors
    vector<int> vec1 = {1, 3, 2, 4, 5, 6, 8, 7};
    vector<int> vec2 = {9, 10, 12, 11, 13, 15, 14};

    // Sort the vectors to ensure valid BSTs
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    // Build balanced BSTs directly from sorted vectors
    Node* root1 = buildBalancedBST(vec1, 0, vec1.size() - 1);
    Node* root2 = buildBalancedBST(vec2, 0, vec2.size() - 1);

    // Merge the two BSTs
    Node* newRoot = mergeBSTs(root1, root2);

    // Print the inorder traversal of the original and merged BSTs
    cout << "Before merged:" << endl;

    cout << "root1: ";
    printInorder(root1);
    cout << endl;

    cout << "root2: ";
    printInorder(root2);
    cout << endl;

    cout << "Merged BST: ";
    printInorder(newRoot);
    cout << endl;

    return 0;
}