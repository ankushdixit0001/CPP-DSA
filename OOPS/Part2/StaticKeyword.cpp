#include<iostream>
using namespace std;
void Counter(){
    //static variable initialize with last value
    static int count =0;
    count++;
    cout<<"count : "<<count<<endl;
}
int main() {
    Counter();
    Counter();
    Counter();
    Counter();
    return 0;
}
