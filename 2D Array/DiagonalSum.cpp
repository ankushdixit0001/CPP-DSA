#include<iostream>
using namespace std;

void diagonalsum(int arr[][3], int n){
     int sum=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                sum+=arr[i][j];
            }else if(j==n-i-1){
                sum+=arr[i][j];
            }

        }
     }
     cout<<"sum = "<<sum;
}

void diagonalsum2(int arr[][3], int n){
     int sum=0;
     for(int i=0;i<n;i++){
        sum+=arr[i][i];
        if(i!=n-i-1){
            sum+=arr[i][n-i-1];
        }
        }
     cout<<"sum = "<<sum;
}

int main() {
    int arr[3][3]={{22,33,55},
                 {64,56,34},
                 {34,67,23}};
                 diagonalsum2(arr,3); 
    return 0;
    }
