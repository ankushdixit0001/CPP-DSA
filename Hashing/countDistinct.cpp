#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to count and display distinct elements
void countDistinct(const vector<int>& nums) {
    unordered_set<int> elementSet; // Stores distinct elements

    // Insert all elements into the unordered_set (O(n) complexity)
    for (int num : nums) {
        elementSet.insert(num);
    }

    // Output number of distinct elements
    cout << "Number of distinct elements: " << elementSet.size() << endl;

    // Display distinct elements (unordered)
    cout << "Distinct elements: ";
    for (const auto& num : elementSet) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Sample input
    vector<int> nums = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};

    // Call function to find and display distinct elements
    countDistinct(nums);

    return 0;
}