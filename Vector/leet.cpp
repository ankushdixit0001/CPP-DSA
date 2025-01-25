#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> median(vector<int> nums1 , vector<int> nums2){
   vector<int> vec=nums1;
   for(int i=0;i<nums2.size();i++){
      vec.push_back(nums2[i]);
   }
   sort(vec.begin(),vec.end());
   // int vec.size() = vec.size();
   cout<<" vec.size() = "<<vec.size()<<endl;
   if(vec.size()%2==0){
      cout<<"median = "<<(double)(vec[vec.size()/2]+vec[vec.size()/2-1])/2<<endl;
   }
   else {
      cout<<"Median ="<<vec[vec.size()/2];
   }
}

int main() {
    vector<int> nums1={2,1};
    vector<int> nums2={5,4};
    median(nums1,nums2);

    return 0;
}
