#include<iostream>
#include<vector>
using namespace std;
int firstoccur(vector<int> arr,int i,int key){
    if(i==arr.size()){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstoccur(arr,i+1,key);
}
int main() {
    vector<int> arr={1,2,3,3,4,4,5,6};
    int i=0;
    int key =6;
    cout<<firstoccur(arr,i,key);
    return 0;
}
