#include<iostream>
#include<vector>
using namespace std;

class Heap {
    vector<int> vec;

public:
    // Insert an element into the heap
    void push(int val) {
        // Step 1: Add the element to the end of the vector
        vec.push_back(val);

        // Step 2: Fix the heap property (heapify up)
        int x = vec.size() - 1;
        int parI = (x - 1) / 2;

        while (parI >= 0 && vec[x] > vec[parI]) {
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x - 1) / 2;
        }
    }

    // Heapify down from index i
        void heapify(int i) { // i = parI
        if (i >= vec.size()) {
            return;
        }
        int l = 2 * i + 1;
        int r = 2 * i + 2;
    
        int maxIdx = i;
    
        // Check if the left child is greater
        if (l < vec.size() && vec[l] > vec[maxIdx]) {
            maxIdx = l;
        }
    
        // Check if the right child is greater
        if (r < vec.size() && vec[r] > vec[maxIdx]) {
            maxIdx = r;
        }
    
        // If the largest is not the current node, swap and continue heapifying
        if (maxIdx != i) {
            swap(vec[i], vec[maxIdx]);
            heapify(maxIdx);
        }
    }

    // Remove the top element (maximum element in max heap)
    void pop() {
        if (vec.empty()) {
            cout << "Heap is empty, cannot pop!" << endl;
            return;
        }
        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();
        heapify(0);
    }

    // Get the top element (maximum element in max heap)
    int top() {
        if (vec.empty()) {
            cout << "Heap is empty!" << endl;
            return -1; // Return an invalid value if the heap is empty
        }
        return vec[0];
    }

    // Check if the heap is empty
    bool empty() {
        return vec.size() == 0;
    }

    // Get the size of the heap
    int size() {
        return vec.size();
    }

    // Print all elements of the heap (for debugging purposes)
    void printHeap() {
        cout << "Heap elements: ";
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;

    // Insert elements into the heap
    h.push(10);
    h.push(20);
    h.push(5);
    h.push(30);
    h.push(15);

    // Print the heap
    h.printHeap();

    // Display the top element
    cout << "Top element: " << h.top() << endl;

    // Remove the top element
    h.pop();
    cout << "After popping top element:" << endl;
    h.printHeap();

    // Check the size of the heap
    cout << "Heap size: " << h.size() << endl;

    // Check if the heap is empty
    cout << "Is heap empty? " << (h.empty() ? "Yes" : "No") << endl;

    return 0;
}
