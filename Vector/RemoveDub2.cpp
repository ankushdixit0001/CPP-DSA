#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (j == 1 || nums[i] != nums[j - 2]) {
                nums[j++] = nums[i];
            }
        }
        return j;
}

int main() {
    vector<int> nums={0,0,1,1,1,1,2,3,3};
    removeDuplicates(nums);
    return 0;
}
