#include <iostream>
#include <queue>
using namespace std;

// Custom comparator for the priority_queue
struct comparePair {
    bool operator()(pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second < p2.second; // Max-heap: higher second value has higher priority
    }
};

int main() {
    priority_queue<pair<string, int>, vector<pair<string, int>>, comparePair> pq;

    int n;
    cout << "Enter the number of pairs: ";
    cin >> n;

    // Input pairs dynamically
    for (int i = 0; i < n; i++) {
        string name;
        int value;
        cout << "Enter name and value for pair " << i + 1 << ": ";
        cin >> name >> value;
        pq.push(make_pair(name, value));
    }

    // Display pairs in descending order of their second value
    cout << "\nPairs in descending order of their second value:\n";
    while (!pq.empty()) {
        cout << "Name: " << pq.top().first << ", Value: " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}
