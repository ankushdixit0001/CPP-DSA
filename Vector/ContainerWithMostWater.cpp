#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int left=0, right=n-1;
    int Area =0 , ans = 0;
    while (left<=right)
    {

        int breath = right-left;
        Area = breath*min(height[left] , height[right]);
        ans = max(ans , Area);
        if(height[left]<height[right]){
            left++;
        }
        else{
            right--;
        }
    }
    cout<<"Max Water = "<<ans;
    return ans;
    }

int main() {
    vector<int> height={1,8,6,2,5,4,8,3,7};
    maxArea(height);
    return 0;
}
