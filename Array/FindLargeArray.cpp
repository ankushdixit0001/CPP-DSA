#include<iostream>
using namespace std;
 
int main() {
    int arr[] = {2,3,99,6,9};
    int n = sizeof(arr)/sizeof(int);
    int max = 0;
    for(int i=0 ; i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<"max = "<<max<<endl;
    return 0;
}
 