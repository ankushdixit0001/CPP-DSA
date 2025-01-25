#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<char> s; //define here type of data
    s.push('a');
    s.push('b');
    s.push('c');
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
