#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n=nums.size();
    for (int i = 0; i < n; i++) {
            if (nums[i]==target) {
                return i;
            } 
            else if(nums[i]!=target&&nums[i]>target) {
                return i;
            }
        }
        return n;
    
}

int main() {
    vector<int> nums = {1,3,5,6};
    int target = 8;
   cout<<searchInsert(nums, target);
    return 0;
}
