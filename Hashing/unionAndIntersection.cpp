#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to compute union and intersection of two vectors
void unionIntersection(const vector<int>& nums1, const vector<int>& nums2) {
    unordered_set<int> unionSet, intersectionSet, tempSet;

    // Insert elements from nums1 into unionSet (O(n1))
    for (int num : nums1) {
        unionSet.insert(num);
        tempSet.insert(num); // Used to check intersection
    }

    // Insert elements from nums2 into unionSet (O(n2))
    for (int num : nums2) {
        unionSet.insert(num);
    }

    // Check for intersection with tempSet (O(n2))
    for (int num : nums2) {
        if (tempSet.count(num)) {
            intersectionSet.insert(num);
        }
    }

    // Display results
    cout << "Union: ";
    for (const auto& num : unionSet) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Intersection: ";
    for (const auto& num : intersectionSet) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Sample input vectors
    vector<int> nums1 = {7, 3, 9};
    vector<int> nums2 = {6, 3, 9, 2, 9, 4};

    // Compute union and intersection
    unionIntersection(nums1, nums2);

    return 0;
}