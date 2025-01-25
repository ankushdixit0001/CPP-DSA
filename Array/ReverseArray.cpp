#include<iostream>
using namespace std;

 int Reverse(int arr[], int n){
    int start =0 , end=n-1;
    while(start < end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
   for(int i=0;i<n;i++){
        cout<< arr[i]<<" " ;   
    }
    return 0;
 }

 int ExtraReverse(int arr[],int n){
    int darr[n];
    for(int i=0;i<n;i++){
        darr[i]=arr[n-i-1];
    }
    for(int i=0;i<n;i++){
        cout<< darr[i]<<" " ;
    }
    return 0;
 }

int main() {
    int arr[] = {2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    cout<<"n = "<<n<<endl;
    ExtraReverse(arr,n);
    cout<<endl;
    Reverse(arr,n);
    return 0;
}
