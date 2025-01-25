#include<iostream>
#include<vector>
using namespace std;

// vector<int> brut(vector<int> arr, int target){
//     int n=arr.size();
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             if(arr[i]+arr[j]==target){
//                 cout<<"he";
//             }
//         }
//     }
// }

vector<int> pairsum(vector<int> arr, int target){
    int st=0 , end=arr.size()-1;
    int cursum=0;
    vector<int> ans;

    while (st<end)
    {
        cursum= arr[st] + arr[end];
        if(cursum==target){
             ans.push_back(st);
             ans.push_back(end);
             return ans;
        }
        else if(cursum>target){
            end--;
        }
        else{
            st++;
        }
    }
    return ans;
    
}

int main() {
    vector<int> arr={2,7,11,15};
    int target=9;
    vector<int> ans = pairsum(arr , target);
    cout<<ans[0] <<" , "<<ans[1];
    return 0;
}
