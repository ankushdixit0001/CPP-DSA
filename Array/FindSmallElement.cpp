#include<iostream>
using namespace std;

int main() {
     int arr[] = {2,3,99,6,9};
    int n = sizeof(arr)/sizeof(int);
    int small = arr[0] ;
    for(int i=0;i<n;i++){
        if(small>arr[i]){
            small=arr[i];
        }
    }
    cout<< "small = "<<small;
    return 0;
}
