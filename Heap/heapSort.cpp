#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int> &vec, int i, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxIdx = i;
    if (left < n && vec[left] > vec[maxIdx]) {
        maxIdx = left;
    }
    if (right < n && vec[right] > vec[maxIdx]) {
        maxIdx = right;
    }
    if (maxIdx != i) {
        swap(vec[i], vec[maxIdx]);
        heapify(vec, maxIdx, n);
    }
}

void heapSort(vector<int> &vec) {
    int n = vec.size();

    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(vec, i, n);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(vec[0], vec[i]);

        // Call max heapify on the reduced heap
        heapify(vec, 0, i);
    }
}

int main() {
    vector<int> vec = {2, 3, 6, 4, 5, 7};
    heapSort(vec);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    return 0;
}
