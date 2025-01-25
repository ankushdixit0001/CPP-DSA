#include<iostream>
using namespace std;

void Maxsubarray( int arr[] , int n){
    //brute force approach
    int maxsum=INT8_MIN;
    for(int start = 0 ; start<n ; start++){
        for(int end = start ; end<n; end++){
            int sum=0;  // cout<<"(" <<start<< "," <<end<< ")";
            for(int i=start;i<=end;i++){
                
                sum=sum+arr[i];
                
            }
            cout<<sum<<",";
            maxsum = max(maxsum , sum);
        }
        cout<<endl;
    } 
    cout<<"maxsum = "<<maxsum;
}
void maxsumkadans(int *arr, int n){
    int maxsum=INT8_MIN;
    int cursum = 0;
    for(int i = 0;i<n;i++){
        cursum+=arr[i];
        maxsum = max(cursum,maxsum);
        if(cursum<0){
            cursum=0;
        }
    }
    cout<<"maxsum = "<<maxsum;

}

int main() {
    int arr[6] = {2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);
    // Maxsubarray(arr , n);
    maxsumkadans(arr,n);
    return 0;
}