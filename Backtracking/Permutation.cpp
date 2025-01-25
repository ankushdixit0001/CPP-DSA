#include<iostream>
#include<vector>
using namespace std;
void generatePermutations(vector<int>& nums, int start,
                              vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            generatePermutations(nums, start + 1, result);
            swap(nums[start], nums[i]); // backtrack
        }
    }

    // Function to return all permutations of the array
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        generatePermutations(nums, 0, result);
        return result;
    }
int main() {
    vector<int> nums={1,2,3};
    
    permute(nums);
    return 0;
}
