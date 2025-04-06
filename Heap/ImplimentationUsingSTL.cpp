#include <iostream>
#include <queue>
using namespace std;

void printMaxHeap(priority_queue<int> pq) {//pass by value,Create a copy to avoid modifying the original heap
    cout << "Max Heap Elements (Descending Order): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void printMinHeap(priority_queue<int, vector<int>, greater<int>> pQ) {//pass vy value,Create a copy to avoid modifying the original heap
    cout << "Min Heap Elements (Ascending Order): ";
    while (!pQ.empty()) {
        cout << pQ.top() << " ";
        pQ.pop();
    }
    cout << endl;
}

int main() {
    // Max Heap (default behavior of priority_queue)
    priority_queue<int> maxHeap;

    // Insert elements into the max heap
    maxHeap.push(5);
    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(6);
    maxHeap.push(7);
    maxHeap.push(1);

    // Display the top element of the max heap
    cout << "Top element of Max Heap: " << maxHeap.top() << endl;

    // Print all elements of the max heap
    printMaxHeap(maxHeap);

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert elements into the min heap
    minHeap.push(5);
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(6);
    minHeap.push(7);
    minHeap.push(1);

    // Display the top element of the min heap
    cout << "Top element of Min Heap: " << minHeap.top() << endl;

    // Print all elements of the min heap
    printMinHeap(minHeap);

    // Check if heaps are empty
    cout << "Is Max Heap empty? " << (maxHeap.empty() ? "Yes" : "No") << endl;
    cout << "Is Min Heap empty? " << (minHeap.empty() ? "Yes" : "No") << endl;

    return 0;
}
