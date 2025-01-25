#include<iostream>
#include<string.h>
using namespace std;
 void reverse(char arr[] , int n){
    int start=0, end=n-1;
    while(start<=end){
        swap(arr[start] , arr[end]);
        start++;
        end--;
    }
    cout<<"reverse = "<<arr<<endl;
 }
int main() {
    char arr[20];
    cin.getline(arr , 20);
    reverse(arr , strlen(arr));
    return 0;
}
