#include<iostream>
#include<vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    int startingPosition = -1, endingPosition = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                startingPosition = i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i] == target){
                endingPosition = i;
                break;
            }
        }
        cout<<"star position : "<<startingPosition<<" ending position : "<<endingPosition;
        return {startingPosition, endingPosition};
}
int main() {
    vector<int> nums = {5,7,7,8,10};
    int target = 7;
    searchRange(nums,target);
    return 0;
}
