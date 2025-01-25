#include<iostream>
using namespace std;

void bubblesort(int arr[] , int n){
    // if element of i greather then i++ than swap and this is repeat again to n-i.
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionsort(int arr[] , int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[i] , arr[min]);
    }
}
void countsort(int arr[], int n){
    int freq[100000]={0};
    int minval = INT16_MAX , maxval =INT16_MIN;
    for(int i=0;i<n;i++){
         freq[arr[i]]++;
        minval=min(minval,arr[i]);
        maxval=max(maxval,arr[i]);
       
    }
    for(int i=minval,j=0;i<=maxval;i++){
        while(freq[i]>0){
            arr[j++]=i;
            freq[i]--;
        }
    }
}
void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        while(prev>=0&&arr[prev]>curr){
            swap(arr[prev+1],arr[prev]);
            prev--;
        }
        // arr[prev+1]=curr;
    }
}
int main() {
    int arr[]={5,4,1,3,2,200,1};
    int n = sizeof(arr)/sizeof(int);
    selectionsort(arr,n);

    for(int i=0 ;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
