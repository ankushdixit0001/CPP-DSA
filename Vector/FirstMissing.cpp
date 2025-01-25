#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int firstMissingPositive(vector<int>& nums) {
    nums.erase(remove_if(nums.begin(),nums.end(),[](int n) { return n <= 0; }),nums.end());
    sort(nums.begin(),nums.end());
    int key =1;
    
    for(int i=0;i<nums.size();i++){
        if(nums[i]==key){
            key++;
        }
    }
    return key;
}
int main() {
    vector<int> nums={100000, 3, 4000, 2, 15, 1, 99999};
    cout<<firstMissingPositive(nums);
    // cout<<key;
    return 0;
}
