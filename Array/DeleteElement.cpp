#include<iostream>
using namespace std;

int main() {
    int arr[]={1,2,3,3,4,9,6};
    int n=sizeof(arr)/sizeof(int);
    int index=3, element = 3;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(arr[i]==element){
            while(i<n){
                arr[i]=arr[i+1];
                i++;
            }
        }
    }
    // while(index<n){
    //     arr[index]=arr[index+1];
    //     index++;
    // }
    n--;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
