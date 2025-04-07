#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class car {
public:
    int idx;
    int distSq;

    // Constructor
    car(int idx, int distSq) {
        this->idx = idx;
        this->distSq = distSq;
    }

    // Custom comparator for min-heap
    bool operator<(const car &obj) const {
        return this->distSq > obj.distSq; // Min-heap: smaller distance has higher priority
    }
};

void nearbyCars(const vector<pair<int, int>> &pos, int k) {
    // Min-heap to store cars based on their distance
    priority_queue<car> pq;

    // Calculate squared distances and push into the priority queue
    for (int i = 0; i < pos.size(); i++) {
        int distSq = pos[i].first * pos[i].first + pos[i].second * pos[i].second;
        pq.push(car(i, distSq));
    }

    // Retrieve the k nearest cars
    cout << "The " << k << " nearest cars to the origin are:\n";
    for (int i = 0; i < k && !pq.empty(); i++) {
        cout << "Car Index: " << pq.top().idx << ", Squared Distance: " << pq.top().distSq << endl;
        pq.pop();
    }
}

int main() {
    // Input positions of cars
    vector<pair<int, int>> pos = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;

    // Find the k nearest cars
    nearbyCars(pos, k);

    return 0;
}

/*
Time Complexity (TC):
1. Calculating squared distances and pushing into the priority queue: O(n log n)
   - Each push operation takes O(log n), and we do this for all n cars.
2. Retrieving the k nearest cars: O(k log n)
   - Each pop operation takes O(log n), and we do this k times.
Overall Time Complexity: O(n log n)

Space Complexity (SC):
1. Space used by the priority queue: O(n)
   - The priority queue stores all n cars.
2. Space used by the input vector: O(n)
Overall Space Complexity: O(n)
*/
