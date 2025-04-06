#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to maintain the max-heap property
void heapify(vector<int> &vec, int i, int n) {
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index
    int maxIdx = i;        // Assume the current node is the largest

    // Check if the left child is larger than the current node
    if (left < n && vec[left] > vec[maxIdx]) {
        maxIdx = left;
    }

    // Check if the right child is larger than the current largest
    if (right < n && vec[right] > vec[maxIdx]) {
        maxIdx = right;
    }

    // If the largest is not the current node, swap and continue heapifying
    if (maxIdx != i) {
        swap(vec[i], vec[maxIdx]);
        heapify(vec, maxIdx, n); // Recursively heapify the affected subtree
    }
}

// Function to perform heap sort
void heapSort(vector<int> &vec) {
    int n = vec.size();

    // Step 1: Build a max heap
    // Time Complexity: O(n)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(vec, i, n);
    }

    // Step 2: Extract elements from the heap one by one
    // Time Complexity: O(n log n)
    for (int i = n - 1; i > 0; i--) {
        // Move the current root (largest element) to the end
        swap(vec[0], vec[i]);

        // Call max heapify on the reduced heap
        heapify(vec, 0, i);
    }
}

int main() {
    // Input array
    vector<int> vec = {2, 3, 6, 4, 5, 7};

    // Perform heap sort
    heapSort(vec);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity (TC):
1. Building the max heap: O(n)
2. Extracting elements and heapifying: O(n log n)
Overall Time Complexity: O(n log n)

Space Complexity (SC):
1. In-place sorting, so no extra space is used.
Overall Space Complexity: O(1)
*/