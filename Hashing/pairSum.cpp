#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // Define the array and target sum
    int arr[] = {1, 2, 7, 11, 15, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    // Use an unordered_map to store array values and their indices
    unordered_map<int, int> m;

    // Iterate through the array (O(n) time complexity)
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i]; // Find complement needed

        // Check if complement exists in the map
        if (m.count(complement)) {
            cout << "Pair found at indices: " << m[complement] << " and " << i << endl;
            return 0; // Exit after finding the first valid pair
        }

        // Store the current element and its index in the map
        m[arr[i]] = i;
    }

    cout << "No valid pair found." << endl;
    return 0;
}