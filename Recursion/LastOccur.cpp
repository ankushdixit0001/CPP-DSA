#include<iostream>
#include<vector>
using namespace std;
int LastOccur(vector<int> arr,int i,int key){
    if(i==-1){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return LastOccur(arr,i-1,key);
}
int main() {
    vector<int> arr={1,2,3,3,4,4,5,6};
    int i=arr.size();
    int key =45;
    cout<<LastOccur(arr,i,key);
    return 0;
}