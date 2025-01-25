#include<iostream>
using namespace std;
int fact(int n){
    if(n==0){//base case
        return 1;
    }
    return n*fact(n-1);
}
void main() {
    int n=6;
    cout<<fact(n);
    // return 0;
}
