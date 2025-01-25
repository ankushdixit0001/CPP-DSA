#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int removeElement(vector<int>& nums, int val) {
    int j=0;
        for(int i = 0 ; i<nums.size(); i++){
            if(nums[i]!=val){
                nums[j]=nums[i];
                j++;
                cout<<nums[i]<<" ";
            }
            
        } 
        return j;
    }


int main() {
    vector<int> nums={2,3,4,5,2};
    removeElement(nums , 2);
    return 0;
}

