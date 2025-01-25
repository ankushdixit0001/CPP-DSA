#include<iostream>
using namespace std;
int friendspair(int n ){
    if(n==1||n==2){
        return n;
    }
    return friendspair(n-1)+(n-1)*friendspair(n-2);
}
int main() {
    cout<<friendspair(3);
    return 0;
}
