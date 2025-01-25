#include<iostream>
#include<list>
using namespace std;
template<class T>
class Stack{
    list<T> ll;
    public:
    void push(T val){
        ll.push_front(val);
    }
    void pop(){
        ll.pop_front();
    }
    T top(){
        return ll.front();
    }
    bool isEmpty(){
        return ll.size()==0;
    }
};
int main() {
    Stack<char> s; //define here type of data
    s.push('a');
    s.push('b');
    s.push('c');
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
