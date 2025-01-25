#include<iostream>
using namespace std;

int BiSearch(int arr[], int key ,int n){
    int start = 0 , end = n-1;
    
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if (key>arr[mid]){
            start = mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int main() {
    int arr[] ={2, 9, 24, 35, 56, 61, 67, 93};
    int n = sizeof(arr)/sizeof(int);
    int key = 9;
    cout<<BiSearch(arr,key,n);
    return 0;
}
