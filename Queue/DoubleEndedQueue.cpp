#include<iostream>
#include<deque>
using namespace std;
//by linked list , i have to try it.

int main() {
    deque<int> deq;
    deq.push_back(2);
    deq.push_front(1);
    deq.push_back(3);
    deq.push_back(4);
    while(!deq.empty()){
        cout<<deq.front()<<" ";
        deq.pop_front();
    }
    return 0;
}
