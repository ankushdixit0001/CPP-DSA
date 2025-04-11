#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to find majority elements that appear more than ⌊n/3⌋ times
void majorityElement(const vector<int>& nums) {
    unordered_map<int, int> freqMap; // Stores element frequencies

    // Count occurrences of each element (O(n) complexity)
    for (const int& num : nums) {
        freqMap[num]++;
    }

    cout << "Majority elements (appearing more than n/3 times): ";
    
    // Traverse the frequency map to find elements with frequency > n/3 (O(n) complexity)
    for (const auto& element : freqMap) {
        if (element.second > nums.size() / 3) {
            cout << element.first << " ";
        }
    }
    cout << endl;
}

int main() {
    // Sample input array
    vector<int> nums = {1, 3, 2, 5, 1, 3, 1, 5, 1};

    // Call function to find majority elements
    majorityElement(nums);

    return 0;
}