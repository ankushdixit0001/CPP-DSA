#include<iostream>
using namespace std;

int main() {
    // int arr[3][3];
    int arr[3][3]={{22,33,55},
                 {64,56,34},
                 {34,67,23}};

    // for(int i=0;i<3;i++){
    //         for(int j=0;j<3;j++){
    //             cin>>arr[i][j];
    //         }
    //         cout<<endl;
    //     }
    // cout<<endl;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
