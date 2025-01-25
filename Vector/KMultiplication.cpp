#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    for(int i=1;i<=k;i++){
        int min = INT8_MAX;
        int index=-1;
        for(int j=0;j<nums.size();j++){
            if(nums[j]<min){
                min=nums[j];
                index=j;
            }
        }
        nums[index]=nums[index]*multiplier;
    }
    return nums;
}
int main() {
    vector<int> nums = {2,1,3,5,6};
    int k = 5, multiplier = 2;
    getFinalState(nums,k,multiplier);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
